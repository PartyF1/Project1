/*  Дана квадратная целочисленная матрица размера не менее 3 строки на
    3 столбца.Произвести циклический сдвиг элементов внешнего слоя
    матрицы по часовой стрелке, а элементов следующего за ним слоя –
    против часовой стрелки.

*/
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <ctime>
#include <vector>
using namespace std;


//Функция  создания и заполнения матрицы случайными числами
// a - входня матрица, n - количество строк и столбцов
void randomMatrix(vector<vector<int>> &a, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) 
    {
        vector<int> tmp;
        for (int j = 0; j < n; j++) 
            tmp.push_back(rand() % 100);   
        a.push_back(tmp);
    }
    
}

//Функция вывода матрицы
// a - входня матрица, n - количество строк и столбцов
void printMatrix(vector<vector<int>> a)
{
    for (auto row = a.begin(); row != a.end(); row++)
    {
        for (auto col = row->begin(); col != row->end(); col++)
            cout << setw(4) << *col;
        cout << endl;
    }
}

//Переворачивает внешние витки матрицы по часовой стрелке
// a - входня матрица, n - количество строк и столбцов
void turnOut(vector<vector<int>> &a) {
    int bottom = a.size() - 1;
    int top = 0;
    

    //Переворот верхней строки
    int temp1 = a.at(top).at(bottom); // Переменная с временным значением стартовой точки
    for (auto j = a.at(top).rbegin(); j != a.at(top).rend()-1; j++) {
         *j = *(j+1);
    }
    //Переворот правого столбца
    int temp2 = a.at(bottom).at(bottom); // Вспомогательная временная переменная
    for (int j = bottom; j > top; j--) {
        if (j == top+1) {
            a.at(j).at(bottom) = temp1;
        }
        else {
            a.at(j).at(bottom) = a.at(j-1).at(bottom);
        }
    }
    //Переворот нижней строки
    temp1 = a.at(bottom).at(top);
    for (auto j = a.at(bottom).begin(); j != a.at(bottom).end(); j++) {
        if (j == a.at(bottom).end() - 2) {
            *j = temp2;
            break;
        }
        else {
            *j = *(j + 1);
        }
    }
    //Переворот левого столбца
    for (int j = top; j < bottom; j++) {
        if (j == bottom - 1) {
            a.at(j).at(top) = temp1;
        }
        else {
            a.at(j).at(top) = a.at(j+1).at(top);
        }
    }
}

//Переворачивает внутренние витки матрицы против часовой стрелки
// a - входня матрица, n - количество строк и столбцов
void turnIn(vector<vector<int>> &a) {
    int bottom = a.size() - 2;
    int top = 1;


    //Переворот левого столбца
    int temp1 = a.at(bottom).at(top);
    for (int i = bottom; i > top; i--) {
        a.at(i).at(1) = a.at(i-1).at(1);
    }
    //Переворот нижней строки   
    int temp2 = a.at(bottom).at(bottom); // Вспомогательная временная переменная
    for (auto j = a.at(bottom).rbegin()+top; j != a.at(bottom).rend()-2; j++) {
        if (j == a.at(bottom).rend() - 3) {
            *j = temp1;
            break;
        }
        else {
            *j = *(j + 1);
        }
    }
    //Переворот правого столбца
    temp1 = a.at(top).at(bottom);
    for (int j = top; j <= bottom - 1; j++) {
        if (j == bottom - 1) {
            a.at(j).at(bottom) = temp2;
        }
        else {
            a.at(j).at(bottom)= a.at(j+1).at(bottom);
        }
    }
    //Переворот верхней строки
    for (auto j = a.at(top).begin(); j != a.at(top).end()-2; j++) {
        if (j == a.at(top).end() - 3) {
            *j = temp1;
            break;
        }
        else {
            *j = *(j + 1);
        }
    }

}







int main()
{
    setlocale(LC_ALL, "RUS");

    int n;
    cout << "Введите размер квадратной матрицы: ";
    cin >> n;
    cout << endl;

    vector<vector<int>> a;

    randomMatrix(a, n);

    cout << "Начальная матрица: " << endl;
    printMatrix(a);

    turnOut(a);
    turnIn(a);

    cout << "Итоговая матрица: " << endl;
    printMatrix(a);
    

    system("pause");
    return 0;

}
