#ifndef TEMPINSTALLATIONDESPAWNEVENT_H_
#define TEMPINSTALLATIONDESPAWNEVENT_H_

#include "engine/engine.h"

//class InstallationObject;

class TempInstallationDespawnEvent : public Event {
	InstallationObject * inso;
	DeedObject *deed;
	Player *player;
	float x;
	float z;
	float y;
	float oX;
	float oZ;
	float oY;
	float oW;

public:
	TempInstallationDespawnEvent(InstallationObject * inInso, Player *play, DeedObject *targetDeed, float x, float z, float y, float oX, float oZ, float oY, float oW) : Event() {

		inso = inInso;
		deed = targetDeed;
		player = play;
		this->x = x;
		this->z = z;
		this->y = y;
		this->oX = oX;
		this->oZ = oZ;
		this->oY = oY;
		this->oW = oW;

		setKeeping(false);
	}

	bool activate() {

		cout << "TempInstallationDespawnEvent::activate()" << endl;



		inso->removeFromZone();
		inso->finalize();

		PlanetManager *planetManager = player->getZone()->getPlanetManager();

		cout << "TempInstallationDespawnEvent::activate() Deed object type is = " << deed->getObjectType() << " sub object type = " << deed->getObjectType() << endl;
		switch(deed->getObjectSubType()) {
			case TangibleObjectImplementation::INSTALLATIONDEED:

				switch(DeedObjectImplementation::getSubType(deed->getObjectCRC())){
					case TangibleObjectImplementation::HARVESTER:
						planetManager->spawnHarvester(player, (HarvesterDeed*)deed, x, z, y, oX, oZ, oY, oW);
						break;
					case TangibleObjectImplementation::FACTORY:
					case TangibleObjectImplementation::GENERATOR:
					case TangibleObjectImplementation::TURRET:
					case TangibleObjectImplementation::MINEFIELD:
						planetManager->spawnInstallation(player, deed, x, z, y, oX, oZ, oY, oW);
						break;
				}
				break;
			case TangibleObjectImplementation::BUILDINGDEED:
				planetManager->spawnBuilding(player, deed, x, z, y, oX, oZ, oY, oW);
				break;

			default:
				break;
		}

		return true;
	}

};

#endif /*TEMPINSTALLATIONDESPAWNEVENT_H_*/
