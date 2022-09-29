/*
Дан массив из N вещественных чисел. Найти элементы с минимальным
и максимальным значениями; отсортировать часть массива, состоящую
из находящихся между ними элементов. Разрешается использовать
только один массив.
Автаев С.М.
Лабораторная Н.10
Вариант 14
04.11.21
*/


#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;





vector<double> ::iterator it;
void newVector(vector<double>& a) {
	double x;
	cout << "Вводите числа до 0" << endl;
	cin >> x;
	while (x)
	{
		a.push_back(x);
		cin >> x;
	}

}

//Нахождения максимального и минимального элемента массива и его индекса
void maxMinVector(vector<double>& a, vector<double>::iterator &minN, vector<double>::iterator &maxN, double &max, double &min) {
	minN = a.begin(), maxN = a.begin();
	for (it = a.begin() + 1; it != a.end(); it++)
	{
		if (*it < *minN) {
			minN = it;
			min = *it;
		}
		if (*it > *maxN) {
			maxN = it;
			max = *it;
		}
	}
}


//Функция сортировки массива
void sortVector(vector<double>& a, vector<double>::iterator minN, vector<double>::iterator maxN) {
	if (minN < maxN) {
		sort(minN, maxN);
	}
	else if (minN > maxN) {
		sort(maxN, minN, greater<double>());
	}
}

void outVector(vector<double>& a) {
	for (it = a.begin(); it != a.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}



int main()
{
	setlocale(LC_ALL, "Russian");

	vector<double> a;
	newVector(a);
	cout << endl;

	vector<double>::iterator minN; vector<double>::iterator maxN;
	double min = *a.begin();
	double max = *a.begin();
	maxMinVector(a, minN, maxN, max, min);
	cout << "Максимальный элемент: " << max << endl;
	cout << "Минимальный элемент: " << min << endl;

	sortVector(a, minN, maxN);

	outVector(a);

	system("pause");
	return 0;

}
