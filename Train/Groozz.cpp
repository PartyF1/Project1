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
	cout << "�������� ����� �" << getNum() << " ����������������� � " << getCapacity() << " ����" << endl;
}

void Groozz::enter(std::istream& cin)
{
	cout << "������� �����, ��� � ���������������� ������" << endl;
	int num, weight;
	cin >> num >> weight >> this->capacity;
	setNum(num); setWeight(weight); 
}
