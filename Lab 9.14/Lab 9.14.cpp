/* Дано натуральное число n.Реализовать булевскую рекурсивную функцию, возвращающую истину,
если десятичная запись цифр этого числа
является палиндромом, и ложь – в противном случае.

*/

#include <iostream>
#include <string>
using namespace std;

//Проверяет, Является ли десятичная запись цифр числа палиндромом
//S - записанное в виде строки десятичное число
bool isPalindrome(string s)
{
    return s.length() <= 1 ? true
        : s[0] == s[s.length() - 1] && isPalindrome(s.substr(1, s.length() - 2));
}
//Переводит число n в строку
string Converter(int n) {
    return to_string(n);
}

//Вывод результата палиндромности числа n
void PollOut(int n) {
    if (isPalindrome(Converter(n))) {
        cout << "Число " << n << " является палиндромом";
    }
    else {
        cout << "Число " << n << " не является палиндромом";
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;
    cout << endl;

    PollOut(n);
}

