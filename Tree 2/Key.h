#pragma once
#include <iostream>
#include <string>

using namespace std;
struct Key
{
	string type;
	bool uniq;
	int value;

	Key(string type, int value) {
		this->type = type;
		this->value = value;
		if (type == "idP" || type == "tableNum") this->uniq = true;
		else this->uniq = false;
	}
	Key() {
		this->type = "";
		this->value = NULL;
		this->uniq = false;
	}

	friend istream& operator>>(istream& cin, Key& key) {
		cout << "������� �������� �����:" << endl;
		cout << "1. idP" << endl;
		cout << "2. ��������� �����" << endl;
		cout << "3. �����" << endl;
		cout << "4. ���" << endl;
		cout << "5. ����� ����������" << endl;

		int input;
		cin >> input;
		switch (input)
		{
		case 1: key.type = "idP";  key.uniq = true; break;
		case 2: key.type = "tabelNum"; break;
		case 3:	key.type = "month"; break;
		case 4: key.type = "year"; break;
		case 5: key.type = "salary"; break;
		}
		cout << "������� �������� ���������� ���������" << endl;
		cin >> input;
		key.value = input;
		return cin;
	}
};