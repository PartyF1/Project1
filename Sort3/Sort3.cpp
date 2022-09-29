// Sort3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Используется змейка из двух частей: вначале сверху вниз по строкам «вправо-влево» до побочной диагонали матрицы, потом снизу вверх по строкам «вправо-влево» от побочной диагонали матрицы.

//

#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;

void newMatrix(int**& a, int n)
{
	a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
}

void randomMatrix(int**& a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 100;
}

int* matrixToArray(int** a, int n) {
	int* b = new int[n * n];
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			b[k] = a[i][j];
			k++;
		}
	return b;
}

int* sortMatrix(int** a, int n) {
	int* arr = matrixToArray(a, n);
	int* c = new int[n*n];
	for (int i = 0; i <= n*n; i++)
		c[i] = 0;
	for (int i = n*n; i >= 1; i--)
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] <= arr[j]) {
				c[i]++;
			}
			else {
				c[j]++;
			}
		}

	int* b = new int[n*n];
	for (int i = 0; i <= n*n; i++) {
		b[c[i]] = arr[i];
	}
	return b;
}

void placeMatrix(int**& a, int m, int* sorted) {
	int f = m;
	int num = 0;
	int i = 0;
	int j = 0;
	//Нечётная матрица
	if (m % 2 != 0) {
		while (i < m - 1) {
			if (i % 2 == 0) {
				while (j < f)
				{
					a[i][j] = sorted[num];
					num++;
					j++;
				}
				f--;
				j = f - 1;
			}
			else {
				while (j >= 0)
				{
					a[i][j] = sorted[num];
					num++;
					j--;
				}
				f--;
				j = 0;
			}
			i++;
		}
		i = m - 1;
		f = 0;
		j = 0;
		while (i >= 1) {
			if (i % 2 == 0) {
				while (j < m)
				{
					a[i][j] = sorted[num];
					num++;
					j++;
				}
				f++;
				j = m - 1;
			}
			else {
				while (j > f)
				{
					a[i][j] = sorted[num];
					num++;
					j--;
				}
				f++;
				j = f + 1;
			}
			i--;
		}
	}
	//Чётная матрица
	else {
		while (i <= m) {
			if (i % 2 == 0) {
				while (j < f)
				{
					a[i][j] = sorted[num];
					num++;
					j++;
				}
				f--;
				j = f - 1;
			}
			else {
				while (j >= 0)
				{
					a[i][j] = sorted[num];
					num++;
					j--;
				}
				f--;
				j = 0;
			}
			i++;
		}
		i = m-1;
		f = 0;
		j = 0;
		num--;
		while (i >= 1) {
			if (i % 2 != 0) {
				while (j < m)
				{
					a[i][j] = sorted[num];
					num++;
					j++;
				}
				f++;
				j = m - 1;
			}
			else {
				while (j > f)
				{
					a[i][j] = sorted[num];
					num++;
					j--;
				}
				f++;
				j = f + 1;
			}
			i--;
		}
	}
}

void printMatrix(int** a, int m) {
	cout << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	int m;
	cout << "Введите размер квадратной матрицы ";
	cin >> m;
	cout << endl;

	int** a = new int* [m];

	newMatrix(a, m);
	randomMatrix(a, m);
	printMatrix(a, m);
	placeMatrix(a, m, sortMatrix(a, m));
	printMatrix(a, m);
}

