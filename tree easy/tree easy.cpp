/*Информационная система «Бухгалтерия 1Ц» рассчитывает начисление заработной
платы работников некоторого предприятия. О каждом начислении зарплаты данные
представлены следующим набором: уникальный идентификатор idP (порядковый номер начисления),
табельный номер работника, месяц, год, начисленная сумма.
Реализовать систему хранения данных о зарплате в виде бинарного дерева поиска,
ключом которого является idP. Обеспечить:
а) добавление нового начисления с автоматическим присваиванием idP;
б) поиск начисления зарплаты по idP;
в) поиск всех начислений зарплаты определённого работника;
г) выдачу всего списка начислений, упорядоченных по idP;
д) удаление начисления по ключу;
е) построение другого бинарного дерева поиска, ключом которого является табельный номер,
и выдача списка начисления, упорядоченного по табельным номерам.*/

#include <windows.h>;
#include "WorkerSBTree.h";
#include <iostream>
#include <list>

//Все зачисления
void printSalaries(WorkerSBTree& dataBase) {
	cout << dataBase << endl;
}

//Добавление нового зачисления
void newSalary(WorkerSBTree& dataBase, int tabelNum, int month, int year, int salary) {
	const bool complete = dataBase.insert(*new Worker(tabelNum, month, year, salary), "idP");
	if (complete) {
		cout << "Вставка успешна" << endl;
	}
	else {
		cout << "Ошибка вставки" << endl;
	}
	printSalaries(dataBase);
}

//Поиск начисления по idP
void searchSalaries(WorkerSBTree& dataBase, int value) {
	Worker a(dataBase.search("idP", value));
	if (a.get("idP")) {
		cout << a << endl;
	}
	else {
		cout << "Зачисление не найдено" << endl;
	}
	printSalaries(dataBase);
}

list<Worker*> searchAllSalaries(WorkerSBTree& dataBase, int value) {
	list<Worker*> a;
	dataBase.searchList(value, a);
	return a;
}



//Удалить зачисление по idP
void deleteSalary(WorkerSBTree& dataBase, int key) {
	const bool complete = dataBase.erase(key);
	if (complete) {
		cout << "Удаление успешно" << endl;
	}
	else {
		cout << "Ошибка удаления" << endl;
	}
	printSalaries(dataBase);
}

void sortByTabelNum(WorkerSBTree& dataBase, WorkerSBTree& tabelBase) {
	dataBase.newBase(tabelBase);
}

void Menu(WorkerSBTree& dataBase) {
	int i = -1;
	while (i != 0) {
		cout << "Выберите опцию: " << endl;
		cout << "1.Вывести зачисления" << endl;
		cout << "2.Добавить зачисление" << endl;
		cout << "3.Удалить зачисление" << endl;
		cout << "4.Найти все зачисления сотрудника" << endl;
		cout << "5.Найти зачисление по idP" << endl;
		cout << "6.Сортировка по номерам сотрудников" << endl;
		cout << "0.Выйти из программы" << endl;
		cin >> i;

		switch (i)
		{
		case 1: {
			printSalaries(dataBase);
			break;
		}
		case 2: {
			cout << "Последовательно введите: табельный номер, месяц, год, сумма зачисления" << endl;
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			newSalary(dataBase, a, b, c, d);
			break;
		}
		case 3: {
			cout << "Введите номер удаляемого зачисления" << endl;
			int value;
			cin >> value;
			deleteSalary(dataBase, value);
			break;
		}
		case 4: {
			cout << "Введите табельный номер сотрудника" << endl;
			int value;
			cin >> value;
			list<Worker*> salaries = searchAllSalaries(dataBase, value);
			for (auto it : salaries) {
				cout << *it << endl;
			}
			break;
		}
		case 5: {
			cout << "Введите idP зачисления" << endl;
			int value;
			cin >> value;
			searchSalaries(dataBase, value);
			break;
		}
		case 6: {
			WorkerSBTree tabelBase;
			sortByTabelNum(dataBase, tabelBase);
			cout << tabelBase << endl;
			break;
		}
		case 0: {
			break;
		}
		default:
			break;
		}
	}
		
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	WorkerSBTree dataBase;
	Menu(dataBase);
}
