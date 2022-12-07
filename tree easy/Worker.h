#pragma once
#include <iomanip>
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

	int get(string key);
	void setIdP(int idP);

	friend ostream& operator<<(ostream& cout, Worker& worker);

};

