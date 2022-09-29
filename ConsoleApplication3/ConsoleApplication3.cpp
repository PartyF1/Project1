// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int* fibo(int n) {
    int* pers = new int[n+1];
    int a1 = 1;
    int a2 = 1;
    pers[0] = a1; 
    pers[1] = a2;
    for (int i = 2; i < n+1; i++) {
        int temp = a1 + a2;
        pers[i] = temp;
        a1 = a2;
        a2 = temp;
    }
    return pers;
}

static int perimeter(int n) {
    int* a = fibo(n);
    int sum = 0;
    for (int i = 0; i < n+1; i++) {
        sum += a[i];
    }
    delete a;
    return sum * 4;
};

int main()
{
    cout << perimeter(7);
}
