#include "SMSTask.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace chrono;
using namespace std;

SMSTask::SMSTask(const chrono::system_clock::time_point &runTime, const string &taskName)
{
	this->SetTaskName(taskName);
	this->SetRunTime(runTime);
}


SMSTask::~SMSTask()
{
}

void SMSTask::Run()
{
	cout << "SMS sent to " + GetTaskName() << endl;
}