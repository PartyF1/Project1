#pragma once
#include "Vagon.h"
class Passanger: public Vagon
{
private:
	int capacity;
public:
	Passanger();
	Passanger(int capacity);

	int getCapacity();
	void setCapacity(int capacity);

	void print(std::ostream& cout);
	void enter(std::istream& cin);
};

