#include "CardSet.h"

string role[]{ "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
string suit[]{ "hearts", "spades", "diamonds", "clubs" };

//Создание новой колоды из 36 рандомных неповторяющихся карт
void CardSet::newColod(CardSet& set) {
	set.set.clear();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 9; j++) {
			set.set.push_back(Card(role[j], suit[i]));
		}
	}
	srand(unsigned(time(0)));
	random_shuffle(set.set.begin(), set.set.end()); // перемешиваеаем
	setSet(set.set);
};



/*CardSet::CardSet(vector<Card>& set) {
	this->set = set;
}*/

//Создание нового сета из пустой карты
CardSet::CardSet() {
	this->set.push_back(Card());
}

//Добавление карты а в сет
void CardSet::pushToSet(Card a) {
	this->set.push_back(a);
}

//Удаление последней карты из сета
void CardSet::popFromSet() {
	this->set.pop_back();
}

//Установка нового значения общего сета из данного
void CardSet::setSet(vector<Card> set) {
	this->set = set;
};
//Получение значения сета
vector<Card> CardSet::getSet() {
	return set;
};

//Вывод сета на экран
ostream& operator<<(ostream& cout, CardSet& set)
{
	for (auto i = set.set.begin(); i != set.set.end(); i++)
	{
		cout << *i << setw(4);
	}
	cout << endl;
	return cout;
}