#pragma once
#include "LitRes.h"
class Journal: public LitRes
{
private:
	string author;
	string journalName;
	string year;
	string number;
public:
	Journal();
	Journal(string nameRes);
	Journal(string nameRes, string author);
	Journal(string nameRes, string author, string journalName);
	Journal(string nameRes, string author, string journalName, string year);
	Journal(string nameRes, string author, string journalName, string year, string number);
	~Journal();

	string getAuthor();
	string getJournalName();
	string getYear();
	string getNumber();
	
	void setAuthor(string author);
	void setJournalName(string journalName);
	void setYear(string year);
	void setNumber(string number);

	void print(std::ostream& cout);
	void enter(std::istream& cin);
};

