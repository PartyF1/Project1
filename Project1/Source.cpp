#include "WordsVec.h"

int main() {
	setlocale(LC_ALL, "ru");
	WordsVec a;
	a.readFile("word.txt");
	cout << a;
}