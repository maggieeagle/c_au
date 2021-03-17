#include <stdio.h>
#include <iostream>

using namespace std;

int checkOperation(char symb) {
	if (symb != '+' && symb != '-' && symb != '*' && symb != '/' && symb != '0') return 0;
	return 1;
}

int main() {

	setlocale(LC_ALL, "Russian");

	char operation;
	while (true) {

		while (true) {
			operation = getchar();
			getchar();
			if (checkOperation(operation)) break;
			cout << "Введите доступную операцию:";
		}

		if (operation == '0') break;

		double a, b, result;
		bool flag = 0;

		cin >> a;
		cin >> b;

		if (operation == '+') result = a + b;
		if (operation == '-') result = a - b;
		if (operation == '*') result = a * b;
		if (operation == '/')
			if (b == 0) flag = 1;
			else result = a / b;
		if (flag == 0) cout << a << ' ' << operation << ' ' << b << " = " << result << endl;
		else cout << "Деление на ноль!" << endl;

	}
	return 0;
}
