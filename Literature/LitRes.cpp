#include "LitRes.h"

LitRes::LitRes()
{
	this->nameRes = "";
}

LitRes::LitRes(string nameRes)
{
	this->nameRes = nameRes;
}

LitRes::~LitRes()
{
}

void LitRes::setNameRes(string name) {
	this->nameRes = name;
};
string LitRes::getNameRes() {
	return nameRes;
};

void LitRes::print(std::ostream& cout)
{
	cout << this->nameRes;
}
;

void LitRes::enter(std::istream& cin) 
{
	cout << "Введите название источника: ";
	cin >> this->nameRes;
	cout << endl;
}

std::ostream& operator<<(std::ostream& cout, LitRes& a)
{
	a.print(cout);
	return cout;
}

std::istream& operator>>(std::istream& cin, LitRes& a)
{
	a.enter(cin);
	return cin;
}
