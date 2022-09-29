// CardGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "CardSet.h"

//Возвращает строку победителя из s1 и s2
string checkWinners(int s1, int s2) {
    if (s1 > 21 && s2 > 21 && s1 != s2) {
        if (s1 > s2) {
            return "Победил Player2";
        }
        else {
            return "Победил Player1";
        }
    }
    if (s1 == s2) {
        return "Ничья";
    }

    if (s1 < 21 && s2 < 21)
    {
        if (s1 > s2) {
            return "Победил Player1";
        }
        else {
            return "Победил Player2";
        }
    }

    if (s1 > 21 && s2 <= 21) return "Победил Player2";
    if (s1 <= 21 && s2 > 21) return "Победил Player1";

}

//Определяет, можно ли продолжать игру по значению суммы очков s, вводному параметру play и количеству карт a
bool ok(int s, char play, vector<Card> a) {
    if (play == 'n' || s >= 21 || a.size() > 5) return false;
    else return true;
}

//Игра в блэкджек. 2 игрока: Player1, Player2; 2 значения их очков: s1, s2; Одна колода colod
void game(CardSet& Player1, int& s1, CardSet& Player2, int& s2, CardSet& colod) {
    bool kok = true;
    char play1 = 'y';
    char play2 = 'y'; 
    while (kok) {
        cout << "Player1, берёте карту? (y/n)  ";
        cin >> play1;
        kok = ok(s1, play1, Player1.getSet());
        if (kok) {
            Card a = *(colod.getSet().end() - 1);
            colod.popFromSet();
            Player1.pushToSet(a);
            s1 += a.getValue();
            cout << "Кол-во очков Player1: " << s1 << endl;
            kok = ok(s1, play1, Player1.getSet());
            if (kok != true) break;
        }
        else {
            break;
        }
    }
    kok = true;
    cout << endl;

    while (kok) {
        cout << "Player2, берёте карту? (y/n)   ";
        cin >> play2;
        kok = ok(s2, play2, Player2.getSet());
        if (kok) {
            Card a = *(colod.getSet().end() - 1);
            colod.popFromSet();
            Player2.pushToSet(a);
            s2 += a.getValue();
            cout << "Кол-во очков Player2: " << s2 << endl;
            kok = ok(s2, play2, Player2.getSet());
            if (kok != true) break;
        }
        else {
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    CardSet colod;
    colod.newColod(colod);
    CardSet Player1; int s1 = 0;
    CardSet Player2; int s2 = 0;
    game(Player1, s1, Player2, s2, colod);
    cout << "Финальный счёт: Игрок 1: " << s1 << " очков с картами " << Player1 << endl;
    cout << "                Игрок 2: " << s2 << " очков c картами " << Player2 << endl;
    cout << checkWinners(s1, s2) << endl;

    system("pause");
}

