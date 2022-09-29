#include "Journal.h"

Journal::Journal() : LitRes()
{
	this->nameRes = "";
	this->author = "";
	this->journalName = "";
	this->year = "";
	this->number = "";
}

Journal::Journal(string nameRes) : LitRes(nameRes)
{
	this->nameRes = nameRes;
	this->author = "";
	this->journalName = "";
	this->year = "";
	this->number = "";
}

Journal::Journal(string nameRes, string author) : LitRes(nameRes)
{
	this->nameRes = nameRes;
	this->author = author;
	this->journalName = "";
	this->year = "";
	this->number = "";
}

Journal::Journal(string nameRes, string author, string journalName) : LitRes(nameRes)
{
	this->nameRes = nameRes;
	this->author = author;
	this->journalName = journalName;
	this->year = "";
	this->number = "";
}

Journal::Journal(string nameRes, string author, string journalName, string year) : LitRes(nameRes)
{
	this->nameRes = nameRes;
	this->author = author;
	this->journalName = journalName;
	this->year = year;
	this->number = "";
}

Journal::Journal(string nameRes, string author, string journalName, string year, string num) : LitRes(nameRes)
{
	this->nameRes = nameRes;
	this->author = author;
	this->journalName = journalName;
	this->year = year;
	this->number = num;
}

Journal::~Journal()
{
}

string Journal::getAuthor()
{
	return author;
}

string Journal::getJournalName()
{
	return journalName;
}

string Journal::getYear()
{
	return year;
}

string Journal::getNumber()
{
	return number;
}

void Journal::setAuthor(string author)
{
	this->author = author;
}

void Journal::setJournalName(string journalName)
{
	this->journalName = journalName;
}

void Journal::setYear(string year)
{
	this->year = year;
}

void Journal::setNumber(string num)
{
	this->number = num;
}

void Journal::print(std::ostream& cout)
{
	if (this->nameRes != "")
	cout << this->nameRes << endl;
	if (this->author != "")
		cout << this->author << "   ";
	if (this->journalName != "")
		cout << this->journalName << "   ";
	if (this->year != "")
		cout << this->year << "   ";
	if (this->number != "")
		cout << "є" << this->number << endl;
}

void Journal::enter(std::istream& cin)
{
	cout << "¬ведите название статьи: ";
	getline(cin, this->nameRes);
	cout << endl;

	cout << "¬ведите автора статьи: ";
	getline(cin, this->author);
	cout << endl;

	cout << "¬ведите название журнала: ";
	getline(cin, this->journalName);
	cout << endl;

	cout << "¬ведите год выпуска: ";
	getline(cin, this->year);
	cout << endl;

	cout << "¬ведите номер журнала: ";
	getline(cin, this->number);
	cout << endl;

}

