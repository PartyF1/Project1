#include "WordsVec.h"

WordsVec::WordsVec()
{
}

WordsVec::WordsVec(vector<Word> words)
{
	this->words = words;
}

bool comp(Word a, Word b) {
	int s1 = a.getSum();
	int s2 = b.getSum();
	return s1 > s2;
}

bool IsParenthesesOrDash(char c)
{
	switch (c)
	{
	case '(':
	case ')':
	case '-':
	case '"':
	case ',':
	case '.':
	case ';':
	case ':':
		return true;
	default:
		return false;
	}
}

bool getUnic(string word, vector<Word>& allWords)
{
	for (int i = 0; i < allWords.size(); i++) {
		if (word == allWords[i].getWord()) {
			return false;
		}
	}
	return true;
}

vector<Word> WordsVec::getWords()
{
	return words;
}

void WordsVec::setWords(vector<Word> words)
{
	this->words = words;
}


void WordsVec::readFile(string fileName)
{
	ifstream inputFile(fileName, ios::in);
	if (!inputFile)
	{
		cerr << "���� ���������� �������" << endl;
		exit(1);
	}
	//�������� ����� �� �������
	if (inputFile.peek() == EOF) {
		inputFile.close();
		exit(1);
	}
	
	do {
		//���������� ����������� �����
		string thisWord;
		inputFile >> thisWord;
		//���������� ����� � ������ �������
		for (int i = 0; i < thisWord.size(); i++) {
			thisWord[i] = tolower(thisWord[i]);
		}
		//�������� ��������� ��������
		thisWord.erase(remove_if(thisWord.begin(), thisWord.end(), &IsParenthesesOrDash), thisWord.end());
		Word a(thisWord);
		//�������� ����� �� ������������ � ����������
		if (getUnic(a.getWord(), this->words)) {
			this->words.push_back(a);	
		}
		else {
			for (int i = 0; i < this->words.size(); i++)
			{
				if (this->words[i].getWord() == a.getWord())
				{
					this->words[i].addSum();
					break;
				}
			}
		}
	} while (!inputFile.eof());
	sort(this->words.begin(), this->words.end(), comp);
	inputFile.close();
}




std::ostream& operator<<(std::ostream& cout, WordsVec& a)
{
	int size = a.getWords().size();
	if (size < 5) {
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << a.getWords()[i] << endl;
		}
	}
	else {
		for (int i = 0; i < 5; i++)
		{
			cout << i + 1 << ". " << a.getWords()[i] << endl;
		}
	}
	return cout;
}
