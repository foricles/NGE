#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "EObject.h"
#include "SysEnumers.h"
#include "Logger.h"

#include <GLEW\glew.h>
#include <SDL.h>
#include <map>


class ESystem : public EObject
{
public:
	ESystem(SysType systemType);
	virtual ~ESystem();

	virtual bool initialize() = 0;
	virtual bool reset() = 0;
	virtual bool update(GameState *state) = 0;

	SysType type();
	void setAppSystems(std::map<SysType, ESystem*> *sysApp);
protected:
	ESystem *getSystem(SysType type)const;
private:
	SysType oSystemType;
	std::map<SysType, ESystem*> *oSysApp;
};

#endif