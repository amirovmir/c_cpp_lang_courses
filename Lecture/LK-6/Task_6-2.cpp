#include <iostream>
#include <conio.h>
#include <Windows.h>

/*
Задание к лекции 6.2 
Реализовать свой шаблонный класс для умного указателя и программу для демонстрации, что он работает.
*/

using namespace std;

class ToDo {
	char* pName;
	char* date;
public:
	ToDo(char* task, char* b_date) {
		pName = new char[strlen(task) + 1];
		date = new char[strlen(b_date) + 1];

		memcpy(pName, task, strlen(task) + 1);
		memcpy(date, b_date, strlen(b_date) + 1);
	}

	~ToDo() {
		delete pName;
		delete date;
	}

	void Display() {
		cout << "Task: " << pName << endl;
		cout << "Deadline: " << date << endl;
	}
};

template<typename T>
class MyPointer {
private:
	T* pData;
public:
	MyPointer(T* pValue): pData(pValue) {
	}

	~MyPointer() {
		delete pData;
	}

	T& operator*() {
		return *pData;
	}

	T* operator->() {
		return pData;
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	char task[30] = "Сдать долги по проге";
	char data[10] = "1.12.2021";

	MyPointer<ToDo> n(new ToDo(task, data));
	n->Display();

	return 0;
}
