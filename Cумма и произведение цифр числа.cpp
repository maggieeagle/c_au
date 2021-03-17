#include <stdio.h>
#include <iostream>

using namespace std;

int checkNum(char str[]) {
	char num1 = str[0];
	char num2 = str[1];
	char num3 = str[2];

	if (num1 != '0' && num1 != '1' && num1 != '2' && num1 != '3' && num1 != '4' && num1 != '5' &&
		num1 != '6' && num1 != '7' && num1 != '8' && num1 != '9') return 0;
	if (num2 != '0' && num2 != '1' && num2 != '2' && num2 != '3' && num2 != '4' && num2 != '5' &&
		num2 != '6' && num2 != '7' && num2 != '8' && num2 != '9') return 0;
	if (num3 != '0' && num3 != '1' && num3 != '2' && num3 != '3' && num3 != '4' && num3 != '5' &&
		num3 != '6' && num3 != '7' && num3 != '8' && num3 != '9') return 0;
	return 1;
}

int main(){

	setlocale(LC_ALL, "Russian");

	char str[100];

	while (true){
		gets_s(str);
		//std::cout << str;
		int length = strlen(str);
		//cout << length << endl;
		if (strlen(str) == 3 && str[0] != '-' && str[0] != '0' && checkNum(str) == 1) break;
		else cout << "Введено не трехзначное положительное число, попробуйте еще раз:";
	}
	int num1 = (int)str[0] - 48;
	int num2 = (int)str[1] - 48;
	int num3 = (int)str[2] - 48;
	cout << "Сумма цифр числа: " << num1 + num2 + num3 << endl;
	cout << "Произведение цифр числа: " << num1 * num2 * num3;

	return 0;
}
