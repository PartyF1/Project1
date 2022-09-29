/*
Дан список из n целых чисел 𝑎0, 𝑎1, … , 𝑎(𝑛−1) (|𝑎𝑖| <= 100). 
Проверить, можно ли, удалив ровно один элемент, получить из списка палиндром?
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

// Функция создает двусвязный список с двумя сторожами и заполняет
// его значениями с клавиатуры
void CreateList(List*& head, List*& tail, int n)
{
	head = new List;
	tail = new List;
	head->next = tail;
	tail->pred = head;

	List* last = head;

	for (int i = 0; i < n; i++)
	{
		List* p = new List;
		p->info = rand() % 2;
		last = InsertElementIntoList(last, p);
	}

}

//Удаляет элемент из списка(если он не первый после головы), возвращает следующий за ним элемент
List* RemoveElement(List* p)
{
	List* p1 = p->pred;
	List* p2 = p->next;
	p1->next = p2;
	p2->pred = p1;
	return p2;
}

//Вывод списка на экран
void PrintList(List* head, List* tail)
{
	List* p = head->next;
	while (p != tail)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}

//Проверка списка от головы до хвоста на полиндромность, список палиндром - вернёт true
bool itsPaly(List* head, List* tail, int n) {
	List* start = head->next;
	List* finish = tail->pred;
	int i = 0;
	while (i < n) {
		if (start->info == finish->info) {
			start = start->next;
			finish = finish->pred;
			i++;
			continue;
		}
		else return false;
	}
	return true;
}

//Поочерёдно просматривает элементы списка, при удалении которых строка может стать палиндромом
void PalyCheck(List* head, List* tail, int n) 
{
	int index = 0; //для подсчёта индекса
	List* p = head->next;
	bool ok = true;
	while (p != tail) 
	{
		List* p1;
		int temp = p->info;
		if (p->pred == head) {
			p1 = p->next;
			head->next = p1;
			p1->pred = head;
		}
		else {
			p1 = RemoveElement(p);
		}
		if (itsPaly(head, tail, n/2))
		{
			cout << "Данная строка станет палиндромом при удалении элемента " << p->info << " с индексом " << index << endl;
			ok = false;
		};	
		List* p2 = InsertElementIntoList(p1->pred, p);
		p = p2->next;
		index++;
	} 
	if (ok) cout << "Данный список не сможет быть палиндромом при удалении одного элемента" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	List* head = NULL;
	List* tail = NULL;
	srand(time(NULL));
	List* p;
	
	int n;
	cout << "Введите кол-во элементов от 1 до 100" << endl;
	cin >> n;

	CreateList(head, tail, n);

	PrintList(head, tail);

	PalyCheck(head, tail, n);

	system("pause");
}
