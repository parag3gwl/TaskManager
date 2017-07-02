#include "TaskManager.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

TaskManager* TaskManager::_instance; 


TaskManager::TaskManager() 
{
}

void TaskManager::push(pair<chrono::system_clock::time_point, ITask*> &subscriber)
{
	
	mtx.lock();
	auto t = time(nullptr);
	struct tm timestruct;
	localtime_s(&timestruct, &t);
	std::cout << "TaskManager::push = " << std::put_time(&timestruct, "%d-%m-%Y %H-%M-%S") << std::endl;

	pq.push(subscriber);
	mtx.unlock();
	cv.notify_all();
}

TaskManager* TaskManager::GetInstance()
{
	if (_instance == nullptr)
		_instance = new TaskManager();

	return _instance;
}

bool TaskManager::Pred()
{
	bool rVal = false;
	if (true == pq.empty())
	{
		rVal = false;
	}
	else
	{
		rVal = true;
	}

	return rVal;
}

void TaskManager::DispatchFunction()
{	
	while (1)
	{
		unique_lock<mutex> lk(mtx);
		cv.wait_until(lk, sleeptime, [this] {return Pred(); });

		pair<chrono::system_clock::time_point, ITask*> test = pq.top();
		if (test.first <= chrono::system_clock::now())
		{
			auto t = time(nullptr);
			struct tm timestruct;
			localtime_s(&timestruct, &t);
			std::cout << "DispatchFunction Run() = " << std::put_time(&timestruct, "%d-%m-%Y %H-%M-%S") << std::endl;
			thread runThread(&ITask::Run, (pq.top().second));
			runThread.detach();
			delete(pq.top().second);
			pq.pop();

			if (!pq.empty())
				sleeptime = pq.top().first;
			else
				sleeptime = chrono::system_clock::now() + chrono::hours(10);
			
			
		}
		else
		{
			sleeptime = pq.top().first;
		}
	}
}