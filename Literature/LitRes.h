#pragma once
#include <clocale>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
class LitRes
{
protected:
	string nameRes;
public:
	LitRes();
	LitRes(string nameRes);
	virtual ~LitRes();

	void setNameRes(string name);
	string getNameRes();

	virtual void print(std::ostream& cout);
	virtual void enter(std::istream& cin);


	friend std::ostream& operator<<(std::ostream& cout, LitRes& a);
	friend std::istream& operator>>(std::istream& cin, LitRes& a);
};

