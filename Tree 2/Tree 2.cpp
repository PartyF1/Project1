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
#include <windows.h>

#include "WorkerSBTree.h"

void autoInserter(WorkerSBTree& dataBase, Key key) {
	dataBase.insert(*new Worker(331, 4, 2020, 6), key);
	dataBase.insert(*new Worker(200, 4, 2020, 600), key);
	dataBase.insert(*new Worker(6044, 5, 2020, 600), key);
	dataBase.insert(*new Worker(6044, 6, 2020, 600), key);
	dataBase.insert(*new Worker(423, 12, 2020, 600), key);
	dataBase.insert(*new Worker(306, 7, 2021, 600), key);
}

Key keyHandler() {
	Key a;
	cin >> a;
	return a;
}

void Menu(WorkerSBTree dataBase) {
	int input = -1;
	while (input != 0) {
		cout << "Чего изволите?" << endl;
		cout << "1.Вывести имеющиеся зачисления" << endl;
		cout << "2.Удалить имеющиеся зачисления" << endl;
		cout << "3.Добавить зачисление" << endl;
		cout << "4.Упорядочить по табельному номеру сотрудников" << endl;
		cout << "5.Найти зачисление по ключу" << endl;
		cout << "6.Удалить зачисление по ключу" << endl;
		cin >> input;
		switch (input)
		{
		case(1): {
			cout << dataBase;
			break;
		}
		case(2): {
			dataBase.clear();
			break;
		}
		case(3): {
			break;
		}
		case(4): {
			//autoInserter();
		}
		default:
			break;
		}
	}
}

int main()
{
	// Локализация по кириллице
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	WorkerSBTree dataBase;
	
	autoInserter(dataBase, keyHandler());
	cout << dataBase;

	Key key;
	cin >> key;
	Worker a(dataBase.search(key));
	cout << (a);   
}
