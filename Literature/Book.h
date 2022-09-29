#pragma once
#include "LitRes.h"
class Book : public LitRes
{
private:
	string author;
	string publisher;
	string year;
public:
	Book();
	Book(string nameRes);
	Book(string nameRes, string author);
	Book(string nameRes, string author, string publisher);
	Book(string nameRes, string author, string publisher, string year);
	~Book();
	
	string getAuthor();
	string getPublisher();
	string getYear();

	void setAuthor(string author);
	void setPublisher(string publisher);
	void setYear(string year);

	void print(std::ostream& cout);
	void enter(std::istream& cin);
};

