#pragma once
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class Vagon
{
private:
	int num;
	int weight;
public:
	Vagon();
	Vagon(int num);
	Vagon(int num, int weight);
	~Vagon();

	void setNum(int num);
	void setWeight(int weight);
	int getNum();
	int getWeight();

	virtual void print(std::ostream& cout);
	virtual void enter(std::istream& cin);

	friend class Passanger;
	friend class Groozz;

	friend std::ostream& operator<<(std::ostream& cout, Vagon& a);
	friend std::istream& operator>>(std::istream& cin, Vagon& a);
};

