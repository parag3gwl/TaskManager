#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>
#include "ITask.h"
using namespace std;

typedef pair<chrono::system_clock::time_point, ITask*> PAIR;

class CompareDist
{
public:
	bool operator()(PAIR n1, PAIR n2) {
		return (n1.first > n2.first);
	}
};

class TaskManager
{
private:
	
	chrono::system_clock::time_point sleeptime = chrono::system_clock::now() + chrono::hours(10);
	mutex mtx;
	condition_variable cv;
	priority_queue<PAIR, vector<PAIR>, CompareDist> pq;
	static TaskManager* _instance;

public:
	TaskManager();
	bool Pred();
	void DispatchFunction();
	void push(pair<chrono::system_clock::time_point, ITask*> &subscriber);
	static TaskManager* GetInstance();
};

