/*
 *	server/zone/managers/auction/AuctionsMap.cpp generated by engine3 IDL compiler 0.60
 */

#include "AuctionsMap.h"

#include "server/zone/objects/auction/AuctionItem.h"

#include "server/zone/objects/creature/CreatureObject.h"

/*
 *	AuctionsMapStub
 */

enum {RPC_ADDITEM__CREATUREOBJECT_SCENEOBJECT_AUCTIONITEM_ = 6,RPC_REMOVEITEM__SCENEOBJECT_AUCTIONITEM_,RPC_GETITEM__LONG_,RPC_CONTAINSITEM__LONG_,RPC_GETVENDORITEMCOUNT__SCENEOBJECT_,RPC_DELETETERMINALITEMS__SCENEOBJECT_,RPC_GETBAZAARITEMCOUNT__CREATUREOBJECT_,RPC_UPDATEUID__SCENEOBJECT_STRING_STRING_,RPC_UPDATEVENDORSEARCH__SCENEOBJECT_BOOL_};

AuctionsMap::AuctionsMap() : ManagedObject(DummyConstructorParameter::instance()) {
	AuctionsMapImplementation* _implementation = new AuctionsMapImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("AuctionsMap");
}

AuctionsMap::AuctionsMap(DummyConstructorParameter* param) : ManagedObject(param) {
	_setClassName("AuctionsMap");
}

AuctionsMap::~AuctionsMap() {
}



int AuctionsMap::addItem(CreatureObject* player, SceneObject* vendor, AuctionItem* item) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDITEM__CREATUREOBJECT_SCENEOBJECT_AUCTIONITEM_);
		method.addObjectParameter(player);
		method.addObjectParameter(vendor);
		method.addObjectParameter(item);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->addItem(player, vendor, item);
}

int AuctionsMap::removeItem(SceneObject* vendor, AuctionItem* item) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REMOVEITEM__SCENEOBJECT_AUCTIONITEM_);
		method.addObjectParameter(vendor);
		method.addObjectParameter(item);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->removeItem(vendor, item);
}

AuctionItem* AuctionsMap::getItem(unsigned long long id) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETITEM__LONG_);
		method.addUnsignedLongParameter(id);

		return static_cast<AuctionItem*>(method.executeWithObjectReturn());
	} else
		return _implementation->getItem(id);
}

bool AuctionsMap::containsItem(unsigned long long id) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CONTAINSITEM__LONG_);
		method.addUnsignedLongParameter(id);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->containsItem(id);
}

TerminalListVector AuctionsMap::getVendorTerminalData(const String& planet, const String& region, SceneObject* vendor) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getVendorTerminalData(planet, region, vendor);
}

TerminalListVector AuctionsMap::getBazaarTerminalData(const String& planet, const String& region, SceneObject* vendor) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getBazaarTerminalData(planet, region, vendor);
}

int AuctionsMap::getVendorItemCount(SceneObject* vendor) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETVENDORITEMCOUNT__SCENEOBJECT_);
		method.addObjectParameter(vendor);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getVendorItemCount(vendor);
}

void AuctionsMap::deleteTerminalItems(SceneObject* vendor) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DELETETERMINALITEMS__SCENEOBJECT_);
		method.addObjectParameter(vendor);

		method.executeWithVoidReturn();
	} else
		_implementation->deleteTerminalItems(vendor);
}

int AuctionsMap::getBazaarItemCount(CreatureObject* player) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETBAZAARITEMCOUNT__CREATUREOBJECT_);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getBazaarItemCount(player);
}

void AuctionsMap::updateUID(SceneObject* vendor, const String& oldUID, const String& newUID) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_UPDATEUID__SCENEOBJECT_STRING_STRING_);
		method.addObjectParameter(vendor);
		method.addAsciiParameter(oldUID);
		method.addAsciiParameter(newUID);

		method.executeWithVoidReturn();
	} else
		_implementation->updateUID(vendor, oldUID, newUID);
}

void AuctionsMap::updateVendorSearch(SceneObject* vendor, bool enabled) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_UPDATEVENDORSEARCH__SCENEOBJECT_BOOL_);
		method.addObjectParameter(vendor);
		method.addBooleanParameter(enabled);

		method.executeWithVoidReturn();
	} else
		_implementation->updateVendorSearch(vendor, enabled);
}

DistributedObjectServant* AuctionsMap::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

void AuctionsMap::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	AuctionsMapImplementation
 */

AuctionsMapImplementation::AuctionsMapImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


AuctionsMapImplementation::~AuctionsMapImplementation() {
}


void AuctionsMapImplementation::finalize() {
}

void AuctionsMapImplementation::_initializeImplementation() {
	_setClassHelper(AuctionsMapHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void AuctionsMapImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<AuctionsMap*>(stub);
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* AuctionsMapImplementation::_getStub() {
	return _this.get();
}

AuctionsMapImplementation::operator const AuctionsMap*() {
	return _this.get();
}

void AuctionsMapImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void AuctionsMapImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void AuctionsMapImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void AuctionsMapImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void AuctionsMapImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void AuctionsMapImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void AuctionsMapImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void AuctionsMapImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("AuctionsMap");

}

void AuctionsMapImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(AuctionsMapImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool AuctionsMapImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void AuctionsMapImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = AuctionsMapImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int AuctionsMapImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;

	return _count + 0;
}

AuctionsMapImplementation::AuctionsMapImplementation() {
	_initializeImplementation();
	// server/zone/managers/auction/AuctionsMap.idl():  		allItems.setNullValue(null);
	(&allItems)->setNullValue(NULL);
	// server/zone/managers/auction/AuctionsMap.idl():  		allItems.setNoDuplicateInsertPlan();
	(&allItems)->setNoDuplicateInsertPlan();
	// server/zone/managers/auction/AuctionsMap.idl():  		bazaarCount.setAllowOverwriteInsertPlan();
	(&bazaarCount)->setAllowOverwriteInsertPlan();
	// server/zone/managers/auction/AuctionsMap.idl():  		bazaarCount.setNullValue(0);
	(&bazaarCount)->setNullValue(0);
	// server/zone/managers/auction/AuctionsMap.idl():  		logger.setLoggingName("AuctionsMap");
	(&logger)->setLoggingName("AuctionsMap");
	// server/zone/managers/auction/AuctionsMap.idl():  		logger.setGlobalLogging(true);
	(&logger)->setGlobalLogging(true);
	// server/zone/managers/auction/AuctionsMap.idl():  		logger.setLogging(true);
	(&logger)->setLogging(true);
}

AuctionItem* AuctionsMapImplementation::getItem(unsigned long long id) {
	Locker _locker(_this.get());
	// server/zone/managers/auction/AuctionsMap.idl():  		return allItems.get(id);
	return (&allItems)->get(id);
}

bool AuctionsMapImplementation::containsItem(unsigned long long id) {
	Locker _locker(_this.get());
	// server/zone/managers/auction/AuctionsMap.idl():  		return allItems.contains(id);
	return (&allItems)->contains(id);
}

int AuctionsMapImplementation::getBazaarItemCount(CreatureObject* player) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return bazaarCount.get(player.getObjectID());
	return (&bazaarCount)->get(player->getObjectID());
}

/*
 *	AuctionsMapAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


AuctionsMapAdapter::AuctionsMapAdapter(AuctionsMap* obj) : ManagedObjectAdapter(obj) {
}

void AuctionsMapAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_ADDITEM__CREATUREOBJECT_SCENEOBJECT_AUCTIONITEM_:
		{
			resp->insertSignedInt(addItem(static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<SceneObject*>(inv->getObjectParameter()), static_cast<AuctionItem*>(inv->getObjectParameter())));
		}
		break;
	case RPC_REMOVEITEM__SCENEOBJECT_AUCTIONITEM_:
		{
			resp->insertSignedInt(removeItem(static_cast<SceneObject*>(inv->getObjectParameter()), static_cast<AuctionItem*>(inv->getObjectParameter())));
		}
		break;
	case RPC_GETITEM__LONG_:
		{
			resp->insertLong(getItem(inv->getUnsignedLongParameter())->_getObjectID());
		}
		break;
	case RPC_CONTAINSITEM__LONG_:
		{
			resp->insertBoolean(containsItem(inv->getUnsignedLongParameter()));
		}
		break;
	case RPC_GETVENDORITEMCOUNT__SCENEOBJECT_:
		{
			resp->insertSignedInt(getVendorItemCount(static_cast<SceneObject*>(inv->getObjectParameter())));
		}
		break;
	case RPC_DELETETERMINALITEMS__SCENEOBJECT_:
		{
			deleteTerminalItems(static_cast<SceneObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_GETBAZAARITEMCOUNT__CREATUREOBJECT_:
		{
			resp->insertSignedInt(getBazaarItemCount(static_cast<CreatureObject*>(inv->getObjectParameter())));
		}
		break;
	case RPC_UPDATEUID__SCENEOBJECT_STRING_STRING_:
		{
			String oldUID; String newUID; 
			updateUID(static_cast<SceneObject*>(inv->getObjectParameter()), inv->getAsciiParameter(oldUID), inv->getAsciiParameter(newUID));
		}
		break;
	case RPC_UPDATEVENDORSEARCH__SCENEOBJECT_BOOL_:
		{
			updateVendorSearch(static_cast<SceneObject*>(inv->getObjectParameter()), inv->getBooleanParameter());
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

int AuctionsMapAdapter::addItem(CreatureObject* player, SceneObject* vendor, AuctionItem* item) {
	return (static_cast<AuctionsMap*>(stub))->addItem(player, vendor, item);
}

int AuctionsMapAdapter::removeItem(SceneObject* vendor, AuctionItem* item) {
	return (static_cast<AuctionsMap*>(stub))->removeItem(vendor, item);
}

AuctionItem* AuctionsMapAdapter::getItem(unsigned long long id) {
	return (static_cast<AuctionsMap*>(stub))->getItem(id);
}

bool AuctionsMapAdapter::containsItem(unsigned long long id) {
	return (static_cast<AuctionsMap*>(stub))->containsItem(id);
}

int AuctionsMapAdapter::getVendorItemCount(SceneObject* vendor) {
	return (static_cast<AuctionsMap*>(stub))->getVendorItemCount(vendor);
}

void AuctionsMapAdapter::deleteTerminalItems(SceneObject* vendor) {
	(static_cast<AuctionsMap*>(stub))->deleteTerminalItems(vendor);
}

int AuctionsMapAdapter::getBazaarItemCount(CreatureObject* player) {
	return (static_cast<AuctionsMap*>(stub))->getBazaarItemCount(player);
}

void AuctionsMapAdapter::updateUID(SceneObject* vendor, const String& oldUID, const String& newUID) {
	(static_cast<AuctionsMap*>(stub))->updateUID(vendor, oldUID, newUID);
}

void AuctionsMapAdapter::updateVendorSearch(SceneObject* vendor, bool enabled) {
	(static_cast<AuctionsMap*>(stub))->updateVendorSearch(vendor, enabled);
}

/*
 *	AuctionsMapHelper
 */

AuctionsMapHelper* AuctionsMapHelper::staticInitializer = AuctionsMapHelper::instance();

AuctionsMapHelper::AuctionsMapHelper() {
	className = "AuctionsMap";

	Core::getObjectBroker()->registerClass(className, this);
}

void AuctionsMapHelper::finalizeHelper() {
	AuctionsMapHelper::finalize();
}

DistributedObject* AuctionsMapHelper::instantiateObject() {
	return new AuctionsMap(DummyConstructorParameter::instance());
}

DistributedObjectServant* AuctionsMapHelper::instantiateServant() {
	return new AuctionsMapImplementation();
}

DistributedObjectAdapter* AuctionsMapHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new AuctionsMapAdapter(static_cast<AuctionsMap*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

