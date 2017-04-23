#ifndef _TIME_H_
#define _TIME_H_

#include <time.h>

#include "System.h"

class ETime : public ESystem
{
public:
	ETime();
	~ETime();

	bool initialize() override;
	bool reset() override;
	bool update(GameState *state) override;

	virtual double fps();
	virtual double delaTime();
	virtual double rawTime();
private:
	double oLastTime;

	double oFPS;
	double oDeltaTime;

	double oBeginTime;
};


#endif // !_TIME_H_
