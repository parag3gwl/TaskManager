#include "Timer.h"
#include "EmailTask.h"
#include "SMSTask.h"
#include "thread"
#include <iostream>
using namespace std;
using namespace chrono;

bool GetDurationAndRecepient(system_clock::time_point& expectedTime, string& recepient)
{
	bool blRetVal = false;
	int duration = 0;
	cout << "Enter duration in seconds : ";
	if (!(std::cin >> duration)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input; please re-enter.\n";
		blRetVal = false;
	}
	else{		
		cout << "Enter recepient name : ";
		cin >> recepient;
		expectedTime = system_clock::now() + seconds(duration);
		blRetVal = true;
	}
	return blRetVal;
}

int main()
{
	TaskManager *ptaskManager = TaskManager::GetInstance();
	thread dispatch( &TaskManager::DispatchFunction, ptaskManager);
	int duration = 0;
	short choice = 0;
	while (1)
	{
		cout << "------------------" << endl;
		cout << "| Select Task	 |" << endl;
		cout << "| 1. Email Task  |" << endl;
		cout << "| 2. SMS Task    |" << endl;
		cout << "| 3. Cancel Task |" << endl;
		cout << "| 4. Exit        |" << endl;
		cout << "-----------------" << endl;
		cout << "Enter choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			string recepient;
			system_clock::time_point expectedTime;
			if (GetDurationAndRecepient(expectedTime, recepient))
			{
				EmailTask* eTask1 = new EmailTask(expectedTime, recepient);
				Timer timer(*eTask1);
			}
			break;
		}
		case 2:
		{
			string recepient;
			system_clock::time_point expectedTime;
			if (GetDurationAndRecepient(expectedTime, recepient))
			{
				SMSTask* eTask2 = new SMSTask(expectedTime, recepient);
				Timer timer(*eTask2);
			}
			break;
		}
		case 3:
			//ptaskManager->DislpayNames();
			break;
		case 4:
		default:
		{
			exit(0);
		}
		}
	}	
	return 0;
}