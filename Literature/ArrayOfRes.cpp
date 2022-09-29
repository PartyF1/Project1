#include "ArrayOfRes.h"
#include <algorithm>

ArrayOfRes::ArrayOfRes()
{
	this->resources;
}

ArrayOfRes::~ArrayOfRes()
{
}

//Добавление в массив ссылок книги
void ArrayOfRes::toRes(Book a)
{
	LitRes* b1 = new Book(a);
	this->resources.push_back(b1);
}

//Добавление в массив ссылок журнала
void ArrayOfRes::toRes(Journal a)
{
	LitRes *j1 = new Journal(a);
	this->resources.push_back(j1);
}

//Добавление в массив ссылок интернет-ссылки
void ArrayOfRes::toRes(Url a)
{
	LitRes *u1 = new Url(a);
	this->resources.push_back(u1);
}

//Функция для добавления в массив ссылок нового элемента
void ArrayOfRes::adder()
{
	int ok = 1;
	while (ok) {
		cout << "Добавьте литературный источник." << endl;
		cout << "1. Книга  " << "2.Журнал  " << "3.Интернет-ссылка   " << "0. Выход" << endl;
		char chooser;
		cin >> chooser;
		system("Cls");
		cin.ignore();
		switch (chooser)
		{
		case '1':
		{
			Book b;
			cin >> b;
			toRes(b);
			system("Cls");
			break; 
		}
		case '2':
		{
			Journal b;
			cin >> b;
			toRes(b);
			system("Cls");
			break; 
		}
		case '3':
		{
			Url b;
			cin >> b;
			toRes(b);
			system("Cls");
			break; 
		}
		case '0':
			ok = 0;
			system("Cls");
			break;
		}
	}
}

//Получение Литературного источника под номером num
void ArrayOfRes::getter()
{
	int num;
	int ok = 1;
	while (ok) {
		cout << "Введите номер ссылки, информацию о которой хотите получить, либо введите 0, чтобы закрыть программу ";
		cin >> num;
		system("Cls");
		if (num == 0) break;
		else if (num <= getResourses().size())
		{
			cout << *getResourses()[num-1];
			ok = 0;
		}
		else {
			cout << "Элемента с данным индексом не существует, повторите попытку." << endl;
		}
	}
	
}

/*void ArrayOfRes::eraser(LitRes a) {
	auto it = find(this->resources.begin(), this->resources.end(), a);
	this->resources.erase(it);
}*/
//Возвращает размер массива ссылок
int ArrayOfRes::size()
{
	return this->resources.size();
}
;


//Компаратор для сортировки
bool comp(LitRes *a, LitRes *b) {
	string s1 = (*a).getNameRes();
	string s2 = (*b).getNameRes();
	return s1 <= s2;
}

//Получение массива ссылок
vector<LitRes *> ArrayOfRes::getResourses()
{
	return this->resources;
}

//Изменение массива ссылок на новый массив а
void ArrayOfRes::setResourses(vector<LitRes *> a)
{
	this->resources = a;
}



//Перегрузка вывода массива ссылок на источники
std::ostream& operator<<(std::ostream& cout, ArrayOfRes& a)
{
	
	auto b = a.getResourses();
	sort(b.begin(), b.end(), comp);
	for (int i = 0; i != b.size(); i++)
	{
		LitRes c = *b.at(i);
		cout << i+1 << ". " << c.getNameRes() << endl;
	}
	return cout;
}
