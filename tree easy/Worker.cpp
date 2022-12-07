#include "Worker.h"

Worker::Worker()
{
	this->idP = NULL;
	this->tabelNum = NULL;
	this->month = NULL;
	this->year = NULL;
	this->salary = NULL;
}

Worker::Worker(Worker& worker)
{
	this->idP = worker.idP;
	this->tabelNum = worker.tabelNum;
	this->month = worker.month;
	this->year = worker.year;
	this->salary = worker.salary;
}


Worker::Worker(int tabelNum, int month, int year, int salary)
{
	this->idP = NULL;
	this->tabelNum = tabelNum;
	this->month = month;
	this->year = year;
	this->salary = salary;
}


int Worker::get(string key)
{
	if (key == "idP") {
		return idP;
	}
	else if (key == "tabelNum") {
		return tabelNum;
	}
	else if (key == "month") {
		return month;
	}
	else if (key == "year") {
		return year;
	}
	else if (key == "salary") {
		return salary;
	}
}

void Worker::setIdP(int idP)
{
	this->idP = idP;
}


ostream& operator<<(ostream& cout, Worker& worker)
{
	return cout << setw(12) << worker.idP
		<< setw(12) << worker.tabelNum
		<< setw(10) << worker.month
		<< setw(10) << worker.year
		<< setw(10) << worker.salary;
}
