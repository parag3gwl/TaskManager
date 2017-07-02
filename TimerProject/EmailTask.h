#pragma once
#include "ITask.h"
#include "Timer.h"
#include <string>
using namespace std;

class EmailTask :
	public ITask
{
public:
	EmailTask(EmailTask& ref);
	EmailTask(const chrono::system_clock::time_point &runTime, const string &taskName);
	virtual ~EmailTask();
	void Run();
};

