#pragma once
#include "ITask.h"
#include <queue>
#include "TaskManager.h"
using namespace std;

class Timer
{
public:
	Timer(ITask &subscriber);
	~Timer();

private:
};