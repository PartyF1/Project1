#include "Vagon.h"

Vagon::Vagon()
{
	this->num = 0;
	this->weight = 0;
}

Vagon::Vagon(int num)
{
	this->num = num;
	this->weight = 0;
}

Vagon::Vagon(int num, int weight)
{
	this->num = num;
	this->weight = weight;
}

Vagon::~Vagon()
{
}

void Vagon::setNum(int num)
{
	this->num = num;
}

void Vagon::setWeight(int weight)
{
	this->weight = weight;
}

int Vagon::getNum()
{
	return num;
}

int Vagon::getWeight()
{
	return weight;
}

void Vagon::print(std::ostream& cout)
{
	cout << "Вагон под № " << getNum() << " весом в "<< getWeight() << "тонн." << endl;
}

void Vagon::enter(std::istream& cin)
{
	cout << "Введите номер вагона: ";
	cin >> this->num;
	cout << endl << "Введите вес вагона: ";
	cin >> this->weight;
}

std::ostream& operator<<(std::ostream& cout, Vagon& a)
{
	a.print(cout);
	return cout;
}

std::istream& operator>>(std::istream& cin, Vagon& a)
{
	a.enter(cin);
	return cin;
}
