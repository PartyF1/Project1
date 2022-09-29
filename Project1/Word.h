#pragma once
#include <iostream>
#include <string>
using namespace std;
class Word
{
private:
	string word;
	int sum;
public:
	Word();
	Word(string word);
	Word(string word, int sum);

	string getWord();
	void setWord(string word);
	int getSum();
	void setSum(int sum);

	void addSum();

	friend std::ostream& operator<<(std::ostream& cout, Word& a);
};

