#pragma once
#include <iostream>
#include <string>

using namespace std;
struct Key
{
	string type;
	int value;

	Key(string type, int value) {
		this->type = type;
		this->value = value;
	}
	Key() {
		this->type = "";
		this->value = NULL;
	}

	friend istream& operator>>(istream& cin, Key& key) {
		cout << "Введите параметр ключа:" << endl;
		cout << "1. idP" << endl;
		cout << "2. Табельный номер" << endl;
		cout << "3. Месяц" << endl;
		cout << "4. Год" << endl;
		cout << "5. Сумма начисления" << endl;

		int input;
		cin >> input;
		switch (input)
		{
		case 1: key.type = "idP"; break;
		case 2: key.type = "tabelNum"; break;
		case 3:	key.type = "month"; break;
		case 4: key.type = "year"; break;
		case 5: key.type = "salary"; break;
		}
		cout << "Введите значение выбранного параметра" << endl;
		cin >> input;
		key.value = input;
		return cin;
	}
};