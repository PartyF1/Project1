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

void placeMatrix(int**& a, int m) {
	int f = m;
	int num = 0;
	int i = 0;
	int j = 0;
	//Нечётная матрица
	if (m % 2 != 0) {
		a[i][j] = 0;
		while (i < m-1) {
			if (i % 2 == 0) {
				while (j < f)
				{
					a[i][j] = num;
					num++;
					j++;
				}
				f--;
				j = f - 1;
			}
			else {
				while (j >= 0)
				{
					a[i][j] = num;
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
					a[i][j] = num;
					num++;
					j++;
				}
				f++;
				j = m - 1;
			}
			else {
				while (j > f)
				{
					a[i][j] = num;
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
					a[i][j] = num;
					num++;
					j++;
				}
				f--;
				j = f - 1;
			}
			else {
				while (j >= 0)
				{
					a[i][j] = num;
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
			if (i % 2 != 0) {
				while (j < m)
				{
					a[i][j] = num;
					num++;
					j++;
				}
				f++;
				j = m - 1;
			}
			else {
				while (j > f)
				{
					a[i][j] = num;
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

	int** a = new int*[m];

	newMatrix(a, m);
	placeMatrix(a, m);
	printMatrix(a, m);
}

