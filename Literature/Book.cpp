#include "Book.h"

Book::Book() : LitRes() {
	this->nameRes = "";
	this->author = "";
	this->publisher = "";
	this->year = "";
}

Book::Book(string nameRes) : LitRes(nameRes)
{
	this->nameRes = nameRes;
	this->author = "";
	this->publisher = "";
	this->year = "";
}

Book::Book(string nameRes, string author) : LitRes(nameRes) {
	this->nameRes = nameRes;
	this->author = author;
	this->publisher = "";
	this->year = "";
}

Book::Book(string nameRes, string author, string publisher) : LitRes(nameRes) {
	this->nameRes = nameRes;
	this->author = author;
	this->publisher = publisher;
	this->year = "";
}

Book::Book(string nameRes, string author, string publisher, string year) : LitRes(nameRes) {
	this->nameRes = nameRes;
	this->author = author;
	this->publisher = publisher;
	this->year = year;
}

Book::~Book()
{
}

string Book::getAuthor() {
	return author;
}

string Book::getPublisher() {
	return publisher;
}

string Book::getYear() {
	return year;
}

void Book::setAuthor(string author) {
	this->author = author;
};
void Book::setPublisher(string publisher) {
	this->publisher = publisher;
};
void Book::setYear(string year) {
	this->year = year;
};

void Book::print(std::ostream& cout) {
	if (this->nameRes != "")
	cout << this->nameRes << endl;
	if (this->author != "")
		cout << getAuthor() << "   ";
	if (this->publisher != "")
		cout << getPublisher() << "   ";
	if (this->year != "")
		cout << getYear() << endl;
};

void Book::enter(std::istream& cin) {
	cout << "¬ведите название книги: ";
	getline(cin, this->nameRes);
	cout << endl;

	cout << "¬ведите автора книги: ";
	getline(cin, this->author);
	cout << endl;

	cout << "¬ведите название издательства: ";
	getline(cin, this->publisher);
	cout << endl;

	cout << "¬ведите год выпуска: ";
	getline(cin, this->year);
	cout << endl;
};
