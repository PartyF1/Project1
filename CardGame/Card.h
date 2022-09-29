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

	Card(); //дефолтная карта
	Card(string role, string suit);//общая карта
	Card(string role); //карта дефолтной масти


	void setRole(string role); //установка названия карты
	string getRole(); //получение названия карты
	void setSuit(string suit); // установка масти карты
	string getSuit();//получение масти карты
	int getValue();//получение силы карты
	int findValue(string* roles, string role); //поиск силы карты по названию

	friend std::ostream& operator<<(std::ostream& cout, Card& a); //Вывод карты на экран
};


