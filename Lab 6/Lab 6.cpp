/*
Сочетания. Дано натуральное число n. Построить и вывести множество всех сочетаний
натуральных чисел из n первых натуральных чисел по k чисел в каждом сочетании, для
всех k от 0 до n. Например, для n = 3 искомое множество будет таким: {{}, {1}, {2}, {3},
{1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}. А сколько всего таких сочетаний?
*/

#include <iostream>
#include "Lab 6.h"

//Функция генерирует комбинации элементов с 1 до n
set<set<int>> getCombinations(int n) {
    set<set<int>> combinations;
    int count = 1 << n;
    for (int i = 0; i < count; i++) {
        set<int> combination;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                combination.insert(j + 1);
            }
        }
        combinations.insert(combination);
    }
    return combinations;
}

//Выводит сгенерированный набор комбинаций и их количество в консоль
void printCombinations(set<set<int>> combinations) {
    for (auto combination : combinations) {
        cout << "{";
        for (auto element : combination) {
            cout << element << " ";
        }
        cout << "} "<< endl;
    }
    cout << "Всего комбинаций: " << combinations.size() << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите значение n: ";
    cin >> n;
    printCombinations(getCombinations(n));

    system("pause");
}
