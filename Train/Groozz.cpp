#include "Groozz.h"

Groozz::Groozz()
{
	this->capacity = 0;
}

Groozz::Groozz(int capacity)
{
	this->capacity = capacity;
}

int Groozz::getCapacity()
{
	return this->capacity;
}

void Groozz::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void Groozz::print(std::ostream& cout)
{
	cout << "Грузовой вагон №" << getNum() << " грузоподъёмностью в " << getCapacity() << " тонн" << endl;
}

void Groozz::enter(std::istream& cin)
{
	cout << "Введите номер, вес и грузоподъёмность вагона" << endl;
	int num, weight;
	cin >> num >> weight >> this->capacity;
	setNum(num); setWeight(weight); 
}
