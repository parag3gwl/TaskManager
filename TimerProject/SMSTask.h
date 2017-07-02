#pragma once
#include "ITask.h"
#include "Timer.h"
#include <string>
using namespace std;

class SMSTask :
	public ITask
{
public:
	SMSTask(const chrono::system_clock::time_point &runTime, const string &taskName);
	virtual ~SMSTask();
	void Run();
};

