#pragma once
#include "Groozz.h"
#include "Passanger.h"
#include <vector>
#include <algorithm>
class Stack
{
private:
	vector<Vagon*> vagons;
public:
	Stack();
	
	vector<Vagon*> getVagons();
	void setVagons(vector<Vagon*> a);

	void toStack(Groozz a);
	void toStack(Passanger a);

	void adder();
	void Highest(Stack a);

	friend std::ostream& operator<<(std::ostream& cout, Stack& a);

};

