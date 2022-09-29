#include "Card.h"


string roles[]{ "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
string suits[]{ "hearts", "spades", "diamonds", "clubs" };

Card::Card() {
	this->role = "";
	this->suit = "";
	this->value = findValue(roles, role) > 0 ? findValue(roles, role): 0;
}

Card::Card(string role, string suit) {
	this->role = role;
	this->suit = suit;
	this->value = findValue(roles, role);
}

Card::Card(string role) {
	this->role = role;
	this->suit = "heart";
	this->value = findValue(roles, role);
}

int Card::findValue(string* roles, string role) {
	int i = 6;
	int j = 0;
	while (j < 9) {
		if (role == roles[j]) {
			return i;
			break;
		}
		i++;
		j++;
	}
}

void Card::setRole(string role) {
	this->role = role;
};
string Card::getRole() {
	return role;
};
void Card::setSuit(string suit) {
	this->suit = suit;
};
string Card::getSuit() {
	return suit;
};
int Card::getValue() {
	return value;
};



ostream& operator<<(ostream& cout, Card& a)
{
	cout << a.role << " " << a.suit;
	return cout;
}