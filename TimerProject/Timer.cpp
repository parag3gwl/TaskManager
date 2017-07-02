#include "Timer.h"


Timer::Timer(ITask &subscriber)
{
	TaskManager *pTaskManager = TaskManager::GetInstance();
	pTaskManager->push(make_pair(subscriber.GetRunTime(), &subscriber));
}


Timer::~Timer()
{
}