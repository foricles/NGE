#include "System.h"



ESystem::ESystem(SysType systemType)
	: oSystemType(systemType)
{
}


ESystem::~ESystem()
{
}

SysType ESystem::type()
{
	return oSystemType;
}

void ESystem::setAppSystems(std::map<SysType, ESystem*>* sysApp)
{
	oSysApp = sysApp;
}

ESystem * ESystem::getSystem(SysType type)const
{
	return oSysApp->at(type);
}
