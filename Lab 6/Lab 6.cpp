/*
Сочетания. Дано натуральное число n. Построить и вывести множество всех сочетаний
натуральных чисел из n первых натуральных чисел по k чисел в каждом сочетании, для
всех k от 0 до n. Например, для n = 3 искомое множество будет таким: {{}, {1}, {2}, {3},
{1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}. А сколько всего таких сочетаний?
*/


#include "Lab 6.h"


void getCombinations(set<set<int>>& combinations, int n) {
    for (int i = 1; i <= n; i++) {
        int m = i;
        while (m <= n) {
            set<int> a;
            a.insert(i);
            a.insert(m);
            combinations.insert(a);
            for (int j = m; j > i; j--) {
                a.insert(j);
                combinations.insert(a);
            }
            for (int j = n; j > i; j--) {
                a.insert(j);
                combinations.insert(a);
            }
            m++;
        }
    }
}

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
    set<set<int>> combinations;

    cout << "Введите значение n: ";
    cin >> n;

    getCombinations(combinations, n);
    printCombinations(combinations);

    system("pause");
}
