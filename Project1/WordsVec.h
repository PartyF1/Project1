#pragma once
#include <vector>
#include "Word.h"
#include <fstream>
#include <locale.h>
#include <algorithm>
#include <stdlib.h>
class WordsVec
{
private:
	vector<Word> words;
public:
	WordsVec();
	WordsVec(vector<Word> words);

	void readFile(string fileName);

	vector<Word> getWords();
	void setWords(vector<Word> words);

	friend std::ostream& operator<<(std::ostream& cout, WordsVec& a);
};

