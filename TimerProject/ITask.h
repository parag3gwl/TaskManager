#pragma once
#include <string>
#include <chrono>
using namespace std;

class ITask
{
private:
	string _taskname;
	chrono::system_clock::time_point _runTime;
public:
	string GetTaskName()
	{
		return _taskname;
	}
	
	void SetTaskName(const string &name)
	{
		_taskname = name;

	}

	chrono::system_clock::time_point GetRunTime()
	{
		return _runTime;
	}

	void SetRunTime(const chrono::system_clock::time_point &runTime)
	{
		_runTime = runTime;
	}

	virtual void Run() = 0;
};

