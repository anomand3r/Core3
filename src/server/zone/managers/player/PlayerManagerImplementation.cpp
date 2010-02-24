/*
 * PlayerManagerImplementation.cpp
 *
 *  Created on: 18/07/2009
 *      Author: TheAnswer
 */

#include "PlayerManager.h"

#include "server/zone/packets/charcreation/ClientCreateCharacter.h"
#include "server/zone/packets/charcreation/ClientCreateCharacterCallback.h"
#include "server/zone/packets/charcreation/ClientCreateCharacterSuccess.h"
#include "server/zone/packets/charcreation/ClientCreateCharacterFailed.h"
#include "server/zone/objects/player/Races.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/ZoneProcessServerImplementation.h"
#include "server/zone/managers/name/NameManager.h"
#include "server/db/ServerDatabase.h"
#include "server/chat/ChatManager.h"

#include "server/zone/objects/building/BuildingObject.h"
#include "server/zone/objects/cell/CellObject.h"

#include "server/zone/Zone.h"

PlayerManagerImplementation::PlayerManagerImplementation(ZoneServer* zoneServer, ZoneProcessServerImplementation* impl) :
	ManagedObjectImplementation(), Logger("PlayerManager") {
	server = zoneServer;
	processor = impl;

	playerMap = new PlayerMap(3000);
	nameMap = new CharacterNameMap();

	setGlobalLogging(true);
	setLogging(true);

	loadNameMap();
}

void PlayerManagerImplementation::finalize() {
	delete playerMap;
	playerMap = NULL;

	delete nameMap;
	nameMap = NULL;
}

void PlayerManagerImplementation::loadNameMap() {
	info("loading character names");

	String query = "SELECT * FROM characters";

	ResultSet* res = ServerDatabase::instance()->executeQuery(query);

	while (res->next()) {
		uint64 oid = res->getUnsignedLong(0);
		String firstName = res->getString(3);

		nameMap->put(firstName.toLowerCase(), oid);
	}

	delete res;

	StringBuffer msg;
	msg << "loaded " << nameMap->size() << " character names in memory";
	info(msg.toString(), true);
}

bool PlayerManagerImplementation::existsName(const String& name) {
	bool res = false;

	rlock();

	try {
		res = nameMap->containsKey(name.toLowerCase());
	} catch (...) {
		error("unreported exception caught in bool PlayerManagerImplementation::existsName(const String& name)");
	}

	runlock();

	return res;
}

uint64 PlayerManagerImplementation::getObjectID(const String& name) {
	uint64 oid = 0;

	rlock();

	try {
		oid = nameMap->get(name.toLowerCase());
	} catch (...) {
		error("unreported exception caught in bool PlayerManagerImplementation::existsName(const String& name)");
	}

	runlock();

	return oid;
}

bool PlayerManagerImplementation::checkExistentNameInDatabase(const String& name) {
	if (name.isEmpty())
		return false;

	try {
		String fname = name.toLowerCase();
		MySqlDatabase::escapeString(fname);
		String query = "SELECT * FROM characters WHERE lower(firstname) = \""
					   + fname + "\"";

		ResultSet* res = ServerDatabase::instance()->executeQuery(query);
		bool nameExists = res->next();

		delete res;

		return !nameExists;
	} catch (DatabaseException& e) {
		return false;
	}
}

bool PlayerManagerImplementation::checkPlayerName(MessageCallback* messageCallback) {
	ClientCreateCharacterCallback* callback = (ClientCreateCharacterCallback*) messageCallback;
	ZoneClientSession* client = callback->getClient();

	NameManager* nm = processor->getNameManager();
	BaseMessage* msg = NULL;

	String firstName;

	UnicodeString unicodeName;
	callback->getCharacterName(unicodeName);

	String name = unicodeName.toString();

	//Get the firstname
	int idx = name.indexOf(" ");
	if (idx != -1)
		firstName = name.subString(0, idx);
	else
		firstName = name;

	//Does this name already exist?
	if (nameMap->containsKey(firstName.toLowerCase())) {
		msg = new ClientCreateCharacterFailed("name_declined_in_use");
		client->sendMessage(msg);

		return false;
	}

	//Check to see if name is valid
	int res = nm->validateName(name, callback->getSpecies());

	if (res != NameManagerResult::ACCEPTED) {
		switch (res) {
		case NameManagerResult::DECLINED_EMPTY:
			msg = new ClientCreateCharacterFailed("name_declined_empty");
			break;
		case NameManagerResult::DECLINED_DEVELOPER:
			msg = new ClientCreateCharacterFailed("name_declined_developer");
			break;
		case NameManagerResult::DECLINED_FICT_RESERVED:
			msg = new ClientCreateCharacterFailed("name_declined_fictionally_reserved");
			break;
		case NameManagerResult::DECLINED_PROFANE:
			msg = new ClientCreateCharacterFailed("name_declined_profane");
			break;
		case NameManagerResult::DECLINED_RACE_INAPP:
			msg = new ClientCreateCharacterFailed("name_declined_racially_inappropriate");
			break;
		case NameManagerResult::DECLINED_SYNTAX:
			msg = new ClientCreateCharacterFailed("name_declined_syntax");
			break;
		case NameManagerResult::DECLINED_RESERVED:
			msg = new ClientCreateCharacterFailed("name_declined_reserved");
			break;
		default:
			msg = new ClientCreateCharacterFailed("name_declined_retry");
			break;
		}

		client->sendMessage(msg); //Name failed filters
		return false;
	}

	return true;
}

bool PlayerManagerImplementation::createPlayer(MessageCallback* data) {
	Locker _locker(_this);

	ClientCreateCharacterCallback* callback = (ClientCreateCharacterCallback*) data;
	ZoneClientSession* client = data->getClient();

	String race;
	callback->getRaceFile(race);
	info("trying to create " + race);

	uint32 serverObjectCRC = race.hashCode();

	int raceID = Races::getRaceID(race);
	/*uint32 playerCRC = Races::getRaceCRC(raceID);*/

	UnicodeString name;
	callback->getCharacterName(name);

	if (!checkPlayerName(callback)) {
		info("invalid name " + name.toString());
		return false;
	}

	ManagedReference<SceneObject*> player = server->createObject(serverObjectCRC, 2); // player

	if (player == NULL) {
		error("could not create player... could not create player object");
		return false;
	}

	if (!player->isPlayerCreature()) {
		error("could not create player... wrong object type");
		return false;
	}

	PlayerCreature* playerCreature = (PlayerCreature*) player.get();
	createAllPlayerObjects(playerCreature);

	playerCreature->setRaceID((byte)raceID);

	String playerCustomization;
	callback->getCustomizationString(playerCustomization);
	playerCreature->setCustomizationString(playerCustomization);

	playerCreature->setObjectName(name);

	String firstName = playerCreature->getFirstName();
	String lastName = playerCreature->getLastName();

	firstName.escapeString();
	lastName.escapeString();
	race.escapeString();

	try {
		StringBuffer query;
		query << "INSERT INTO `characters` (`character_oid`, `account_id`, `galaxy_id`, `firstname`, `surname`, `race`, `gender`, `template`)"
				<< " VALUES (" <<  playerCreature->getObjectID() << "," << client->getAccountID() <<  "," << 2 << ","
				<< "'" << firstName << "','" << lastName << "'," << raceID << "," <<  0 << ",'" << race << "')";

		ServerDatabase::instance()->executeStatement(query);
	} catch (Exception& e) {
		error(e.getMessage());
	} catch (...) {
		error("unreported exception caught while creating character");
	}

	nameMap->put(playerCreature);

	//hair
	String hairObjectFile;
	callback->getHairObject(hairObjectFile);

	String hairCustomization;
	callback->getHairCustomization(hairCustomization);

	TangibleObject* hair = createHairObject(hairObjectFile, hairCustomization);

	if (hair != NULL) {
		player->addObject(hair, 4);

		info("created hair object");
	}

	playerCreature->setHeight(callback->getHeight());

	UnicodeString biography;
	callback->getBiography(biography);
	playerCreature->setBiography(biography);

	playerCreature->setClient(client);
	client->setPlayer(player);

	playerCreature->setAccountID(client->getAccountID());

	if (callback->getTutorialFlag()) {
		createTutorialBuilding(playerCreature);
	} else {
		createSkippedTutorialBuilding(playerCreature);
	}

	player->updateToDatabase();

	StringBuffer infoMsg;
	infoMsg << "player " << name.toString() << " successfully created";
	info(infoMsg);

	ClientCreateCharacterSuccess* msg = new ClientCreateCharacterSuccess(player->getObjectID());
	playerCreature->sendMessage(msg);

	ChatManager* chatManager = server->getChatManager();

	chatManager->addPlayer(playerCreature);

	return true;
}

TangibleObject* PlayerManagerImplementation::createHairObject(const String& hairObjectFile, const String& hairCustomization) {
	TangibleObject* hairObject = NULL;

	if (hairObjectFile.isEmpty()) {
		info("hairObjectFile empty");
		return NULL;
	}

	String sharedHairObjectFile = hairObjectFile.replaceFirst("hair_", "shared_hair_");

	info("trying to create hair object " + sharedHairObjectFile);
	SceneObject* hair = server->createObject(sharedHairObjectFile.hashCode(), 1);

	if (hair == NULL) {
		info("objectManager returned NULL hair object");
		return NULL;
	}

	if (hair->getGameObjectType() != SceneObjectImplementation::GENERICITEM) {
		info("wrong hair object type");
		//hair->finalize();

		return NULL;
	} else {
		hairObject = (TangibleObject*) hair;

		hairObject->setCustomizationString(hairCustomization);

		info("hair object created successfully");
	}

	return hairObject;
}

bool PlayerManagerImplementation::createAllPlayerObjects(PlayerCreature* player) {
	SceneObject* inventory = server->createObject(0x3969E83B, 1); // character_inventory

	if (inventory == NULL) {
		error("could not create player inventory");
		return false;
	}

	player->addObject(inventory, 4);

	SceneObject* datapad = server->createObject(0x73BA5001, 1); //datapad

	if (datapad == NULL) {
		error("could not create player datapad");
		return false;
	}

	player->addObject(datapad, 4);

	SceneObject* playerObject = server->createObject(String("object/player/player.iff").hashCode(), 1); //player object

	if (playerObject == NULL) {
		error("could not create player object");
		return false;
	}

	player->addObject(playerObject, 4);

	SceneObject* bank = server->createObject(0x70FD1394, 1); //bank

	if (bank == NULL) {
		error("could not create bank");
		return false;
	}

	player->addObject(bank, 4);

	SceneObject* missionBag = server->createObject(0x3D7F6F9F, 1); //mission bag

	if (missionBag == NULL) {
		error("could not create mission bag");
		return false;
	}

	player->addObject(missionBag, 4);

	// temp

	SceneObject* vibro = server->createObject(0x652688CE, 1);
	player->addObject(vibro, 4);
	player->setWeaponID(vibro->getObjectID());

	SceneObject* vibro2 = server->createObject(0x652688CE, 1);
	inventory->addObject(vibro2, -1);

	String bharmor = "object/tangible/wearables/armor/bounty_hunter/shared_armor_bounty_hunter_chest_plate.iff";
	SceneObject* armor = server->createObject(bharmor.hashCode(), 1);
	inventory->addObject(armor, -1);

	String backpack = "object/tangible/wearables/backpack/shared_backpack_s01.iff";
	SceneObject* backpackObject = server->createObject(backpack.hashCode(), 1);
	inventory->addObject(backpackObject, -1);

	SceneObject* mission = server->createObject(3741732474UL, 1); // empty mission
	datapad->addObject(mission, -1);

	return true;
}

void PlayerManagerImplementation::createTutorialBuilding(PlayerCreature* player) {
	Zone* zone = server->getZone(42);

	String tut = "object/building/general/shared_newbie_hall.iff";
	String cell = "object/cell/shared_cell.iff";

	BuildingObject* tutorial = (BuildingObject*) server->createObject(tut.hashCode(), 1);
	tutorial->createCellObjects();
	tutorial->setStaticBuilding(false);

	SceneObject* travelTutorialTerminal = server->createObject((uint32)String("object/tangible/newbie_tutorial/terminal_warp.iff").hashCode(), 1);

	SceneObject* cellTut = tutorial->getCell(10);
	cellTut->addObject(travelTutorialTerminal, -1);

	tutorial->insertToZone(zone);
	travelTutorialTerminal->initializePosition(27.0f, -3.5f, -168.0f);
	travelTutorialTerminal->insertToZone(zone);

	player->initializePosition(27.0f, -3.5f, -165.0f);
	player->setZone(zone);
	cellTut->addObject(player, -1);
	player->setSavedZoneID(zone->getZoneID());
	player->setSavedParentID(cellTut->getObjectID());

	tutorial->updateToDatabase();
}

void PlayerManagerImplementation::createSkippedTutorialBuilding(PlayerCreature* player) {
	Zone* zone = server->getZone(42);

	String tut = "object/building/general/shared_newbie_hall_skipped.iff";
	String cell = "object/cell/shared_cell.iff";

	BuildingObject* tutorial = (BuildingObject*) server->createObject(tut.hashCode(), 1);
	tutorial->createCellObjects();
	tutorial->setStaticBuilding(false);

	SceneObject* travelTutorialTerminal = server->createObject((uint32)String("object/tangible/newbie_tutorial/terminal_warp.iff").hashCode(), 1);

	SceneObject* cellTut = tutorial->getCell(0);
	cellTut->addObject(travelTutorialTerminal, -1);

	tutorial->insertToZone(zone);
	travelTutorialTerminal->initializePosition(27.0f, -3.5f, -168.0f);
	travelTutorialTerminal->insertToZone(zone);

	player->initializePosition(27.0f, -3.5f, -165.0f);
	player->setZone(zone);
	cellTut->addObject(player, -1);
	player->setSavedZoneID(zone->getZoneID());
	player->setSavedParentID(cellTut->getObjectID());

	tutorial->updateToDatabase();
}
