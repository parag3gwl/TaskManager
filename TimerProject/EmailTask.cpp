#include "EmailTask.h"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

EmailTask::EmailTask(EmailTask& ref)
{
	this->SetTaskName(ref.GetTaskName());
	this->SetRunTime(ref.GetRunTime());
}

EmailTask::EmailTask(const chrono::system_clock::time_point &runTime, const string &taskName)
{
	this->SetTaskName(taskName);
	this->SetRunTime(runTime);
}


EmailTask::~EmailTask()
{
}

void EmailTask::Run()
{
	cout << "Email sent to " + GetTaskName() << endl;
}