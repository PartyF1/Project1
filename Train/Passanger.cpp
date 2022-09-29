#include "Passanger.h"

Passanger::Passanger()
{
	this->capacity = 0;
}

Passanger::Passanger(int capacity)
{
	this->capacity = capacity;
}

int Passanger::getCapacity()
{
	return capacity;
}

void Passanger::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void Passanger::print(std::ostream& cout)
{
	cout << "ѕассажирский вагон є" << getNum() << " вместительностью в " << getCapacity() << " человек" << endl;
}

void Passanger::enter(std::istream& cin)
{
	cout << "¬ведите номер, вес и вместительность вагона" << endl;
	int num, weight;
	cin >> num >> weight >> this->capacity;
	setNum(num); setWeight(weight);
}
