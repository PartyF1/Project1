#pragma once
#include "Vagon.h"
class Groozz: public Vagon
{
private: 
	int capacity;
public:
	Groozz();
	Groozz(int capacity);

	int getCapacity();
	void setCapacity(int capacity);

	void print(std::ostream& cout);
	void enter(std::istream& cin);
};

