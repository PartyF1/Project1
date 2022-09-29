#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;

class Card
{
private:
	string role;
	string suit;
	int value;

public:

	Card(); //��������� �����
	Card(string role, string suit);//����� �����
	Card(string role); //����� ��������� �����


	void setRole(string role); //��������� �������� �����
	string getRole(); //��������� �������� �����
	void setSuit(string suit); // ��������� ����� �����
	string getSuit();//��������� ����� �����
	int getValue();//��������� ���� �����
	int findValue(string* roles, string role); //����� ���� ����� �� ��������

	friend std::ostream& operator<<(std::ostream& cout, Card& a); //����� ����� �� �����
};


