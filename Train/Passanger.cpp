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
	cout << "������������ ����� �" << getNum() << " ���������������� � " << getCapacity() << " �������" << endl;
}

void Passanger::enter(std::istream& cin)
{
	cout << "������� �����, ��� � ��������������� ������" << endl;
	int num, weight;
	cin >> num >> weight >> this->capacity;
	setNum(num); setWeight(weight);
}
