/*Натуральное число n не превосходящее 100 вводится с клавиатуры.Целочисленный линейный массив
a0, a1, …, an - 1 заполняется случайными целыми числами из диапазона[0, n).Требуется отсортировать
массив по не возростанию методом подсчёта и найти значение k последовательным поиском справа налево.
*/

#include <iostream>
#include <iomanip>
using namespace std;

void newArray(int*& a, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % n;
	}
};

void printArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << setw(4) << a[i];
	}
	cout << endl;
};

void sortArray(int* &a, int n) {
	int* c = new int[n];
	for (int i = 0; i <= n; i++)
		c[i] = 0;
	for (int i = n; i >= 1; i--) 
		for (int j = i-1; j >= 0; j--) {
			if (a[i] <= a[j]) {
				c[i]++;
			}
			else {
			c[j]++;
			}	
		}
	
	int* b = new int[n];
	for (int i = 0; i <= n; i++) {
		b[c[i]] = a[i];
	}
	a = b;
};

void findValue(int *a, int n, int k) {
	int* b = new int [n + 1];
	for (int i = 0; i < n; i++) {
		b[i + 1] = a[i];
	}
	int i = n+1;
	b[0] = k;
	while (b[i] != k) {
		i--;
	}
	if (i > 0) 
		cout << "Найден элемент с индексом: " << i-1 << endl;
	else
		cout << "Элемент не найден" << endl;
};


int main()
{
	setlocale(LC_ALL, "ru");

	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	cout << endl;
	int* a = new int[n];

	newArray(a, n);
	printArray(a, n);
	sortArray(a, n);
	printArray(a, n);

	int k;
	cout << "Введите искомое значение: ";
	cin >> k;
	cout << endl;

	findValue(a, n, k);

}
