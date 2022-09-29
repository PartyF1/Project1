#include "ArrayOfRes.h"
#include <Windows.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ArrayOfRes a;
	a.adder();
	cout << a;
	a.getter();
}