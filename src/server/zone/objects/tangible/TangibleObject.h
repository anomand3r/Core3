/*
 *	server/zone/objects/tangible/TangibleObject.h generated by engine3 IDL compiler 0.55
 */

#ifndef TANGIBLEOBJECT_H_
#define TANGIBLEOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/service/Message.h"

#include "../../packets/scene/AttributeListMessage.h"

class Zone;

class SceneObject;

class CreatureObject;

class Player;

class DraftSchematic;

class IntangibleObject;

#include "../scene/SceneObject.h"

class TangibleObject : public SceneObject {
public:
	TangibleObject(unsigned long long oid, int tp = 0);

	TangibleObject(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempname, int tp = 0);

	TangibleObject(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempname, int tp = 0);

	void generateAttributes(Player* player);

	void updateCraftingValues(DraftSchematic* draftSchematic);

	void close(Player* player);

	void setEquipped(bool eqp);

	void sendTo(Player* player, bool doClose = true);

	void sendDeltas(Player* player);

	void repairItem(Player* player);

	void setObjectName(Player* player);

	void parseItemAttributes();

	bool isPersistent();

	bool isUpdated();

	unsigned int getDefenderUpdateCounter();

	unsigned int getNewDefenderUpdateCounter(int cnt);

	char getUnknownByte();

	float getComplexity();

	int getVolume();

	bool isEquipped();

	bool isWeapon();

	bool isArmor();

	bool isClothing();

	bool isContainer();

	bool isWearableContainer();

	bool isContainer1();

	bool isContainer2();

	bool isInstrument();

	bool isAttachment();

	bool isDestroyed();

	bool isAttackable();

	bool isAttackableBy(CreatureObject* creature);

	bool isResource();

	bool isTicket();

	bool isTicketCollector();

	bool isTerminal();

	bool isTool();

	bool isSurveyTool();

	bool isPharmaceutical();

	bool isGenericItem();

	bool isLair();

	bool isDeed();

	bool isInstallation();

	bool isCraftingStation();

	bool isCraftingTool();

	bool isComponent();

	bool isTrap();

	bool isGrenade();

	bool isThrowable();

	bool isWeaponPowerup();

	bool isCamoKit();

	bool isCampKit();

	bool isLoot();

	bool isInsured();

	bool isInsurable();

	bool isDecayable();

	bool isSlicable();

	bool isSliced();

	bool isBeingSliced();

	unsigned long long getSlicerID();

	void setSlicerID(unsigned long long id);

	void setSlicable(bool value);

	void setCraftersName(String& n);

	void setCraftedSerial(String& s);

	void getCustomizationString(String& appearance);

	void setPlayerUseMask(unsigned int mask);

	unsigned int getPlayerUseMask();

	void setOptionsBitmask(unsigned int mask);

	unsigned int getOptionsBitmask();

	int getObjectSubType();

	unsigned int getTemplateID();

	int getObjectCount();

	int getConditionDamage();

	int getMaxCondition();

	int getCondition();

	void doDamage(int damage, SceneObject* attacker);

	String& getCraftersName();

	String& getCraftedSerial();

	void setAttributes(String& attributeString);

	String& getAttributes();

	void addAttributes(AttributeListMessage* alm);

	String& getMisoAsocKey();

	void setLoot(bool l);

	void setMaxCondition(int maxCond);

	void setObjectSubType(const int type);

	void setPersistent(bool pers);

	void setUpdated(bool upd);

	void setConditionDamage(int damage);

	void setCustomizationString(String& cust);

	void setCustomizationVariable(const String& type, unsigned int value);

	void setCustomizationVariable(unsigned char type, unsigned int value);

	void setObjectCount(const int count);

	void setMisoAsocKey(const String& tma);

	void updateOptionsBitmask(Player* player);

	void updateInsurance(Player* player, bool insure);

	void onBroken();

	void onSlicingFailure(Player* slicer);

	void decay(float decayRate);

	void slice(Player* slicer);

	void setItnocrc(unsigned int itnocrc);

	unsigned int getItnocrc();

	IntangibleObject* getITNO();

	void addToDatapad(Player* player);

protected:
	TangibleObject(DummyConstructorParameter* param);

	virtual ~TangibleObject();

	String _return_getAttributes;
	String _return_getCraftedSerial;
	String _return_getCraftersName;
	String _return_getMisoAsocKey;

	friend class TangibleObjectHelper;
};

class TangibleObjectImplementation;

class TangibleObjectAdapter : public SceneObjectAdapter {
public:
	TangibleObjectAdapter(TangibleObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void generateAttributes(Player* player);

	void updateCraftingValues(DraftSchematic* draftSchematic);

	void close(Player* player);

	void setEquipped(bool eqp);

	void sendTo(Player* player, bool doClose);

	void sendDeltas(Player* player);

	void repairItem(Player* player);

	void setObjectName(Player* player);

	void parseItemAttributes();

	bool isPersistent();

	bool isUpdated();

	unsigned int getDefenderUpdateCounter();

	unsigned int getNewDefenderUpdateCounter(int cnt);

	char getUnknownByte();

	float getComplexity();

	int getVolume();

	bool isEquipped();

	bool isWeapon();

	bool isArmor();

	bool isClothing();

	bool isContainer();

	bool isWearableContainer();

	bool isContainer1();

	bool isContainer2();

	bool isInstrument();

	bool isAttachment();

	bool isDestroyed();

	bool isAttackable();

	bool isAttackableBy(CreatureObject* creature);

	bool isResource();

	bool isTicket();

	bool isTicketCollector();

	bool isTerminal();

	bool isTool();

	bool isSurveyTool();

	bool isPharmaceutical();

	bool isGenericItem();

	bool isLair();

	bool isDeed();

	bool isInstallation();

	bool isCraftingStation();

	bool isCraftingTool();

	bool isComponent();

	bool isTrap();

	bool isGrenade();

	bool isThrowable();

	bool isWeaponPowerup();

	bool isCamoKit();

	bool isCampKit();

	bool isLoot();

	bool isInsured();

	bool isInsurable();

	bool isDecayable();

	bool isSlicable();

	bool isSliced();

	bool isBeingSliced();

	unsigned long long getSlicerID();

	void setSlicerID(unsigned long long id);

	void setSlicable(bool value);

	void setCraftersName(String& n);

	void setCraftedSerial(String& s);

	void getCustomizationString(String& appearance);

	void setPlayerUseMask(unsigned int mask);

	unsigned int getPlayerUseMask();

	void setOptionsBitmask(unsigned int mask);

	unsigned int getOptionsBitmask();

	int getObjectSubType();

	unsigned int getTemplateID();

	int getObjectCount();

	int getConditionDamage();

	int getMaxCondition();

	int getCondition();

	void doDamage(int damage, SceneObject* attacker);

	String& getCraftersName();

	String& getCraftedSerial();

	void setAttributes(String& attributeString);

	String& getAttributes();

	void addAttributes(AttributeListMessage* alm);

	String& getMisoAsocKey();

	void setLoot(bool l);

	void setMaxCondition(int maxCond);

	void setObjectSubType(const int type);

	void setPersistent(bool pers);

	void setUpdated(bool upd);

	void setConditionDamage(int damage);

	void setCustomizationString(String& cust);

	void setCustomizationVariable(const String& type, unsigned int value);

	void setCustomizationVariable(unsigned char type, unsigned int value);

	void setObjectCount(const int count);

	void setMisoAsocKey(const String& tma);

	void updateOptionsBitmask(Player* player);

	void updateInsurance(Player* player, bool insure);

	void onBroken();

	void onSlicingFailure(Player* slicer);

	void decay(float decayRate);

	void slice(Player* slicer);

	void setItnocrc(unsigned int itnocrc);

	unsigned int getItnocrc();

	IntangibleObject* getITNO();

	void addToDatapad(Player* player);

protected:
	String _param0_setCraftersName__String_;
	String _param0_setCraftedSerial__String_;
	String _param0_getCustomizationString__String_;
	String _param0_setAttributes__String_;
	String _param0_setCustomizationString__String_;
	String _param0_setCustomizationVariable__String_int_;
	String _param0_setMisoAsocKey__String_;
};

class TangibleObjectHelper : public DistributedObjectClassHelper, public Singleton<TangibleObjectHelper> {
	static TangibleObjectHelper* staticInitializer;

public:
	TangibleObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<TangibleObjectHelper>;
};

#include "../scene/SceneObjectImplementation.h"

class TangibleObjectServant : public SceneObjectImplementation {
public:
	TangibleObject* _this;

public:
	TangibleObjectServant();
	TangibleObjectServant(unsigned long long oid, int type);
	virtual ~TangibleObjectServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*TANGIBLEOBJECT_H_*/
