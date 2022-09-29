#pragma once
#include "Card.h"
#include <vector>

class CardSet
{
private:
	vector<Card> set;
public:
	CardSet(); //�������� ������ ���� �� ������ �����
	//CardSet(vector<Card>& set);
	void newColod(CardSet& set); //�������� ����� ������ �� 36 ����
	void pushToSet(Card); //���������� ����� � � ���
	void popFromSet(); //�������� ��������� ����� �� ����

	void setSet(vector<Card> set); //��������� ������ �������� ������ ���� �� �������
	vector<Card> getSet(); //��������� �������� ����

	

	friend std::ostream& operator<<(std::ostream& cout, CardSet& set); //����� ���� �� �����
};

