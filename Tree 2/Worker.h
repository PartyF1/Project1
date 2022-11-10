#pragma once
#include <iomanip>
#include "Key.h"
using namespace std;
class Worker
{
private:
	int idP;
	int tabelNum;
	int month;
	int year;
	int salary;
public:
	Worker();
	Worker(Worker& worker);
	Worker(int tabelNum, int month, int year, int salary);

	int get(Key key);
	int get(string key);

	void setIdP();
	void setIdP(int idP);

	friend ostream& operator<<(ostream& cout, Worker& worker);

};

