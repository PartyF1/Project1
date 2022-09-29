#include "Stack.h"

Stack::Stack()
{
	this->vagons;
}

vector<Vagon*> Stack::getVagons()
{
	return vagons;
}

void Stack::setVagons(vector<Vagon*> a)
{
	this->vagons = a;
}

void Stack::toStack(Groozz a)
{
	Vagon* g = new Groozz(a);
	this->vagons.push_back(g);
}

void Stack::toStack(Passanger a)
{
	Vagon* p = new Passanger(a);
	this->vagons.push_back(p);
}

void Stack::adder()
{
	int ok = 1;
	while (ok) {
		cout << "�������� �����" << endl;
		cout << "1. ������������  " << "2. ��������  " << "0. �����" << endl;
		char chooser;
		cin >> chooser;
		system("Cls");
		cin.ignore();
		switch (chooser)
		{
		case '1':
		{
			Passanger b;
			cin >> b;
			toStack(b);
			system("Cls");
			break;
		}
		case '2':
		{
			Groozz b;
			cin >> b;
			toStack(b);
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

void Stack::Highest(Stack a)
{
	vector<Vagon*> b = a.getVagons();
	int max = 0;
	int index = 0;
	for (int i = 0; i < b.size(); i++) {
		int weight = (*b[i]).getWeight();
		if (weight > max) {
			max = weight;
			index = i;
		}
	}
	cout << "����� ������ ����� � �������: " << *(b[index]) << endl;
	cout << "��� ����� ����������: " << max << " ����." << endl;
}

std::ostream& operator<<(std::ostream& cout, Stack& a)
{
	int num = 1;
	vector<Vagon*> b = a.getVagons();
	for (int i = 0; i < b.size(); i++) {
		cout << num << ". " << *b[i] << endl;
	}
	cout << endl;
	a.Highest(a);
	return cout;
}
