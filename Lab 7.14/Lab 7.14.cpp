/*  Дана квадратная целочисленная матрица размера не менее 3 строки на
    3 столбца.Произвести циклический сдвиг элементов внешнего слоя
    матрицы по часовой стрелке, а элементов следующего за ним слоя –
    против часовой стрелки.

*/

#include <iostream>
#include <iomanip>
using namespace std;
//Функция создания новой матрицы
// a - входня матрица, n - количество строк и столбцов
void newMatrix(int**& a, int n)
{
    a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
}
//Функция заполнения матрицы случайными числами
// a - входня матрица, n - количество строк и столбцов
void randomMatrix(int** a, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % 100;
}

//Функция вывода матрицы
// a - входня матрица, n - количество строк и столбцов
void printMatrix(int** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

//Переворачивает внешние витки матрицы по часовой стрелке
// a - входня матрица, n - количество строк и столбцов
void turnOut(int** a, int n) {
    int top = 0; // верхняя граница витка
    int bottom = n - 1; // нижняя граница витка
    int left = 0; // левая граница витка
    int right = n - 1; // правая граница витка

    //Переворот верхней строки
    int temp1 = a[top][right]; // Переменная с временным значением стартовой точки
    for (int j = n; j >= 1; j--) {
        a[top][j] = a[top][j-1];
    }
    //Переворот правого столбца
    int temp2 = a[bottom][right]; // Вспомогательная временная переменная
    for (int j = bottom; j >= 1; j--) {
        if (j == 1) {
            a[j][bottom] = temp1;
        }
        else {
            a[j][bottom] = a[j - 1][bottom];
        }
    }
    //Переворот нижней строки
    temp1 = a[bottom][left];
    for (int j = left; j <= right-1; j++) {
        if (j == right-1) {
            a[bottom][j] = temp2;
        }
        else {
            a[bottom][j] = a[bottom][j+1];
        }
    }
    //Переворот левого столбца
    for (int j = top; j <= bottom-1; j++) {
        if (j == right - 1) {
            a[j][left] = temp1;
        }
        else {
            a[j][left] = a[j+1][left];
        }
    }
}
//Переворачивает внутренние витки матрицы против часовой стрелки
// a - входня матрица, n - количество строк и столбцов
void turnIn(int** a, int n) {
    int top = 1; // верхняя граница витка
    int bottom = n - 2; // нижняя граница витка
    int left = 1; // левая граница витка
    int right = n - 2; // правая граница витка

    do {
        //Переворот левого столбца
        int temp1 = a[bottom][left]; // Переменная с временным значением стартовой точки
        for (int j = bottom; j >= top; j--) {
            a[j][left] = a[j - 1][left];
        }
        //Переворот нижней строки
        int temp2 = a[bottom][right]; // Вспомогательная временная переменная
        for (int j = right; j >= left+1; j--) {
            if (j == left+1) {
                a[bottom][j] = temp1;
            }
            else {
                a[bottom][j] = a[bottom][j - 1];
            }
        }
        //Переворот правого столбца
        temp1 = a[top][right];
        for (int j = top; j <= bottom-1; j++) {
            if (j == bottom - 1) {
                a[j][right] = temp2;
            }
            else {
                a[j][right] = a[j + 1][right];
            }
        }
        //Переворот верхней строки
        for (int j = left; j <= right-1; j++) {
            if (j == right - 1) {
                a[top][j] = temp1;
            }
            else {
                a[top][j] = a[top][j + 1];
            }
        }
        //Уменьшения размеров витков
        left++;
        right--;
        top++;
        bottom--;
    } while (left < right || top < bottom);


}







int main()
{
    setlocale(LC_ALL, "Rus");

    int n;
    cout << "Введите размер квадратной матрицы: ";
    cin >> n;
    cout << endl;

    int** a = new int*[n, n];

    newMatrix(a, n);
    randomMatrix(a, n);

    cout << "Начальная матрица: " << endl;
    printMatrix(a, n);

    turnOut(a, n);
    turnIn(a, n);

    cout << "Итоговая матрица: " << endl;
    printMatrix(a, n);

    system("pause");
    return 0;

} 
