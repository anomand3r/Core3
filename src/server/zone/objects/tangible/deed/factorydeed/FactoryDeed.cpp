/*
 *	server/zone/objects/tangible/deed/factorydeed/FactoryDeed.cpp generated by engine3 IDL compiler 0.55
 */

#include "FactoryDeed.h"

#include "FactoryDeedImplementation.h"

#include "../DeedObject.h"

#include "../../TangibleObject.h"

#include "../../../../packets.h"

#include "../../../player/Player.h"

#include "../../../creature/CreatureObject.h"

/*
 *	FactoryDeedStub
 */

FactoryDeed::FactoryDeed(CreatureObject* creature, int tempCRC, const unicode& n, const string& tempn) : DeedObject(DummyConstructorParameter::instance()) {
	_impl = new FactoryDeedImplementation(creature, tempCRC, n, tempn);
	_impl->_setStub(this);
}

FactoryDeed::FactoryDeed(unsigned long long oid, int tempCRC, const unicode& n, const string& tempn) : DeedObject(DummyConstructorParameter::instance()) {
	_impl = new FactoryDeedImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

FactoryDeed::FactoryDeed(DummyConstructorParameter* param) : DeedObject(param) {
}

FactoryDeed::~FactoryDeed() {
}

void FactoryDeed::parseItemAttributes() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((FactoryDeedImplementation*) _impl)->parseItemAttributes();
}

void FactoryDeed::setSurplusMaintenance(int maint) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addSignedIntParameter(maint);

		method.executeWithVoidReturn();
	} else
		((FactoryDeedImplementation*) _impl)->setSurplusMaintenance(maint);
}

void FactoryDeed::setMaintenanceRate(float rate) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addFloatParameter(rate);

		method.executeWithVoidReturn();
	} else
		((FactoryDeedImplementation*) _impl)->setMaintenanceRate(rate);
}

void FactoryDeed::setSurplusPower(int pow) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addSignedIntParameter(pow);

		method.executeWithVoidReturn();
	} else
		((FactoryDeedImplementation*) _impl)->setSurplusPower(pow);
}

void FactoryDeed::setHopperSize(float size) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addFloatParameter(size);

		method.executeWithVoidReturn();
	} else
		((FactoryDeedImplementation*) _impl)->setHopperSize(size);
}

int FactoryDeed::getSurplusMaintenance() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithSignedIntReturn();
	} else
		return ((FactoryDeedImplementation*) _impl)->getSurplusMaintenance();
}

float FactoryDeed::getMaintenanceRate() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithFloatReturn();
	} else
		return ((FactoryDeedImplementation*) _impl)->getMaintenanceRate();
}

int FactoryDeed::getSurplusPower() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithSignedIntReturn();
	} else
		return ((FactoryDeedImplementation*) _impl)->getSurplusPower();
}

float FactoryDeed::getHopperSize() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithFloatReturn();
	} else
		return ((FactoryDeedImplementation*) _impl)->getHopperSize();
}

/*
 *	FactoryDeedAdapter
 */

FactoryDeedAdapter::FactoryDeedAdapter(FactoryDeedImplementation* obj) : DeedObjectAdapter(obj) {
}

Packet* FactoryDeedAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		parseItemAttributes();
		break;
	case 7:
		setSurplusMaintenance(inv->getSignedIntParameter());
		break;
	case 8:
		setMaintenanceRate(inv->getFloatParameter());
		break;
	case 9:
		setSurplusPower(inv->getSignedIntParameter());
		break;
	case 10:
		setHopperSize(inv->getFloatParameter());
		break;
	case 11:
		resp->insertSignedInt(getSurplusMaintenance());
		break;
	case 12:
		resp->insertFloat(getMaintenanceRate());
		break;
	case 13:
		resp->insertSignedInt(getSurplusPower());
		break;
	case 14:
		resp->insertFloat(getHopperSize());
		break;
	default:
		return NULL;
	}

	return resp;
}

void FactoryDeedAdapter::parseItemAttributes() {
	return ((FactoryDeedImplementation*) impl)->parseItemAttributes();
}

void FactoryDeedAdapter::setSurplusMaintenance(int maint) {
	return ((FactoryDeedImplementation*) impl)->setSurplusMaintenance(maint);
}

void FactoryDeedAdapter::setMaintenanceRate(float rate) {
	return ((FactoryDeedImplementation*) impl)->setMaintenanceRate(rate);
}

void FactoryDeedAdapter::setSurplusPower(int pow) {
	return ((FactoryDeedImplementation*) impl)->setSurplusPower(pow);
}

void FactoryDeedAdapter::setHopperSize(float size) {
	return ((FactoryDeedImplementation*) impl)->setHopperSize(size);
}

int FactoryDeedAdapter::getSurplusMaintenance() {
	return ((FactoryDeedImplementation*) impl)->getSurplusMaintenance();
}

float FactoryDeedAdapter::getMaintenanceRate() {
	return ((FactoryDeedImplementation*) impl)->getMaintenanceRate();
}

int FactoryDeedAdapter::getSurplusPower() {
	return ((FactoryDeedImplementation*) impl)->getSurplusPower();
}

float FactoryDeedAdapter::getHopperSize() {
	return ((FactoryDeedImplementation*) impl)->getHopperSize();
}

/*
 *	FactoryDeedHelper
 */

FactoryDeedHelper* FactoryDeedHelper::staticInitializer = FactoryDeedHelper::instance();

FactoryDeedHelper::FactoryDeedHelper() {
	className = "FactoryDeed";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void FactoryDeedHelper::finalizeHelper() {
	FactoryDeedHelper::finalize();
}

DistributedObject* FactoryDeedHelper::instantiateObject() {
	return new FactoryDeed(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* FactoryDeedHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FactoryDeedAdapter((FactoryDeedImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	FactoryDeedServant
 */

FactoryDeedServant::FactoryDeedServant(CreatureObject* creature, int tempCRC, const unicode& n, const string& tempn, int tp) : DeedObjectImplementation(creature, tempCRC, n, tempn, tp) {
	_classHelper = FactoryDeedHelper::instance();
}

FactoryDeedServant::FactoryDeedServant(unsigned long long oid, int tempCRC, const unicode& n, const string& tempn, int tp) : DeedObjectImplementation(oid, tempCRC, n, tempn, tp) {
	_classHelper = FactoryDeedHelper::instance();
}

FactoryDeedServant::~FactoryDeedServant() {
}

void FactoryDeedServant::_setStub(DistributedObjectStub* stub) {
	_this = (FactoryDeed*) stub;
	DeedObjectServant::_setStub(stub);
}

DistributedObjectStub* FactoryDeedServant::_getStub() {
	return _this;
}

