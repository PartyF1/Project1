#pragma once
#include "Book.h"
#include "Journal.h"
#include "Url.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
class ArrayOfRes
{
private:
	vector<LitRes *> resources;
public:
	ArrayOfRes();
	~ArrayOfRes();

	void toRes(Book a);
	void toRes(Journal a);
	void toRes(Url a);
	void adder();
	void getter();

	int size();

	vector<LitRes *> getResourses();
	void setResourses(vector<LitRes *> a);

	friend std::ostream& operator<<(std::ostream& cout, ArrayOfRes& a);
	
};

