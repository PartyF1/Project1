#include "ArrayOfRes.h"
#include <algorithm>

ArrayOfRes::ArrayOfRes()
{
	this->resources;
}

ArrayOfRes::~ArrayOfRes()
{
}

//���������� � ������ ������ �����
void ArrayOfRes::toRes(Book a)
{
	LitRes* b1 = new Book(a);
	this->resources.push_back(b1);
}

//���������� � ������ ������ �������
void ArrayOfRes::toRes(Journal a)
{
	LitRes *j1 = new Journal(a);
	this->resources.push_back(j1);
}

//���������� � ������ ������ ��������-������
void ArrayOfRes::toRes(Url a)
{
	LitRes *u1 = new Url(a);
	this->resources.push_back(u1);
}

//������� ��� ���������� � ������ ������ ������ ��������
void ArrayOfRes::adder()
{
	int ok = 1;
	while (ok) {
		cout << "�������� ������������ ��������." << endl;
		cout << "1. �����  " << "2.������  " << "3.��������-������   " << "0. �����" << endl;
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

//��������� ������������� ��������� ��� ������� num
void ArrayOfRes::getter()
{
	int num;
	int ok = 1;
	while (ok) {
		cout << "������� ����� ������, ���������� � ������� ������ ��������, ���� ������� 0, ����� ������� ��������� ";
		cin >> num;
		system("Cls");
		if (num == 0) break;
		else if (num <= getResourses().size())
		{
			cout << *getResourses()[num-1];
			ok = 0;
		}
		else {
			cout << "�������� � ������ �������� �� ����������, ��������� �������." << endl;
		}
	}
	
}

/*void ArrayOfRes::eraser(LitRes a) {
	auto it = find(this->resources.begin(), this->resources.end(), a);
	this->resources.erase(it);
}*/
//���������� ������ ������� ������
int ArrayOfRes::size()
{
	return this->resources.size();
}
;


//���������� ��� ����������
bool comp(LitRes *a, LitRes *b) {
	string s1 = (*a).getNameRes();
	string s2 = (*b).getNameRes();
	return s1 <= s2;
}

//��������� ������� ������
vector<LitRes *> ArrayOfRes::getResourses()
{
	return this->resources;
}

//��������� ������� ������ �� ����� ������ �
void ArrayOfRes::setResourses(vector<LitRes *> a)
{
	this->resources = a;
}



//���������� ������ ������� ������ �� ���������
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
