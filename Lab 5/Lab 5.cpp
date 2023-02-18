/*
(Считалка Иосифа-2). По кругу становятся n человек, пронумерованных от 1 до n. 
Начиная счет от первого человека, удаляют из круга m-го человека. 
Повторяют это до техпор, пока в кругу не останется последний человек. 
Даны натуральные n и K. 
Найти такое m, чтобы после применения m-считалки для n человек последним бы в круге оказался человек с номером K
или сообщить, что такого m не существует.
*/
#include <iostream>
#include <iterator>
#include <random>
#include <list>
using namespace std;

//В списке people проверяет, остаётся ли k-ый номер, если удалять каждого m-ого
int kill(list<int> people, int m, int k) {
    auto it = people.begin();
    int count = 1;
    while (people.size() > 1)
    {
        if (count == m) {
            if (next(it, 1) != people.end()) {
                auto tempIt = people.erase(next(it, 1));
                it = tempIt == people.end() ? people.begin() : tempIt;
            }
            else {
                people.erase(people.begin());
                it = people.begin();
            }
            count = 1;
        }
        else if (next(it, 1) != people.end()) {
            count++;
            it++;
        }
        else {
            count++;
            it = people.begin();
        }
    }
    if (*it == k) {
        return *it;
    }
}


//Вычисляет выводит все возможное варианты, когда в списке people после применения считалки Иосифа может остаться k-ый член
void Joseph(list<int> people, int k) {
    bool find = false;
    for (int m = 1; m <= people.size(); m++) {
        list<int> temp = people;
        int last = kill(temp, m, k) || 0;
        if (last) {
            cout << "Для " << people.size() << " человек можно убивать каждого " << m << "-ого, чтобы остался человек под номером " << k << endl;
            find = true;
        }
    }
    if (find == false) {
        cout << "Для данного количества и номера не найдётся нужной считалки" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int k, n;
    cout << "Введите кол-во участников" << endl;
    cin >> n;
    cout << endl << "Какой номер должен выжить?" << endl;
    cin >> k;
    list<int> people;

    for (int i = 0; i < n; i++) {
        people.push_back(i+1);
    }

    Joseph(people, k);
}
