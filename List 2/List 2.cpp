/*
    По кругу становятся n человек, пронумерованных от 1 до n. Начиная счет от первого человека, удаляют из круга m-го человека. 
    Повторяют это до тех пор, пока в кругу не останется последний человек. 
    Даны натуральные n и K. 
    Найти такое m, чтобы после применения m-считалки для n человек 
    последним бы в круге оказался человек с номером K или сообщить, что такого m не существует
*/

#include <iostream>
#include <random>
#include <locale.h>
#include <time.h>
using namespace std;

struct List
{
    int info;
    List* next;
    List* pred;
};

//Добавляет элемент в список, возвращает новый элемент
List* InsertElementIntoList(List* last, List* p)
{
    p->next = last->next;
    p->pred = last;
    last->next = p;
    p->next->pred = p;
    return p;
}

// Функция создает двусвязный список с одним сторожем и заполняет
// его значениями номерами участников
void CreateList(List*& head, int n)
{
    head = new List;
    head->next = head;
    head->pred = head;
    int index = 1;
    List* last = head;

    for (int i = 0; i < n; i++)
    {
        List* p = new List;
        p->info = index;
        last = InsertElementIntoList(last, p);
        index++;
    }

}

//Удаляет элемент из списка, возвращает следующий за ним элемент
List* RemoveElement(List* p)
{
    List* p1 = p->pred;
    List* p2 = p->next;
    p1->next = p2;
    p2->pred = p1;
    return p2;
}

//Выводит список на экран
void PrintList(List* head)
{
    List* p = head->next;
    while (p != head)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

//Рекурсивная функция, удаляет элемент p через m пропущенных элементов списка 
List* kill(List* head, List* p, int m) {
    for (int i = 0; i < m; i++) {
        if (p->next != head) p = p->next;
        else p = p->next->next;
    }
    if (p->next == head && p->pred == head) return p;
    else {
        List* p1 = RemoveElement(p);
        //PrintList(head);
        return kill(head, p1, m);
    }
}

//Функция возвращает возможные варианты k-ого человека из n после считалки
void Joseph(List*& head, int k, int n) {
    bool find = false;
    for (int m = 1; m < n; m++) {
        List* p = head->next;
        List* last = kill(head, p, m);
        if (last->info == k) {
            cout << "Для " << n << " человек можно убивать каждого " << m << "-ого, чтобы остался человек под номером " << k << endl;
            find = true;
        }
        CreateList(head, n);
    }
    if (find == false) {
        cout << "Для данного количества и номера не найдётся нужной считалки" << endl;
    }
}





int main()
{
    setlocale(LC_ALL, "Russian");

    List* head = NULL;
    srand(time(NULL));
    List* p;

    int n;
    cout << "Введите кол-во участников" << endl;
    cin >> n;
    int k;
    cout << "Участник с каким номером должен остаться?" << endl;
    cin >> k;

    CreateList(head, n);
    PrintList(head);

    Joseph(head, k, n);
    
}
