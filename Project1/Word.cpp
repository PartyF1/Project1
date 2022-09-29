#include "Word.h"

Word::Word()
{
	this->word = "";
	this->sum = 0;
}

Word::Word(string word)
{
	this->word = word;
	this->sum = 1;
}

Word::Word(string word, int sum)
{
	this->word = word;
	this->sum = sum;
}

string Word::getWord()
{
	return word;
}

void Word::setWord(string word)
{
	this->word = word;
}

int Word::getSum()
{
	return sum;
}

void Word::setSum(int sum)
{
	this->sum = sum;
}

void Word::addSum()
{
	this->sum += 1;
}


std::ostream& operator<<(std::ostream& cout, Word& a)
{
	cout << a.getWord() << " - " << a.getSum();
	return cout;
}



