#pragma once
#include "Card.h"
#include <vector>

class CardSet
{
private:
	vector<Card> set;
public:
	CardSet(); //Создание нового сета из пустой карты
	//CardSet(vector<Card>& set);
	void newColod(CardSet& set); //Создание новой колоды из 36 карт
	void pushToSet(Card); //Добавление карты а в сет
	void popFromSet(); //Удаление последней карты из сета

	void setSet(vector<Card> set); //Установка нового значения общего сета из данного
	vector<Card> getSet(); //Получение значения сета

	

	friend std::ostream& operator<<(std::ostream& cout, CardSet& set); //Вывод сета на экран
};

