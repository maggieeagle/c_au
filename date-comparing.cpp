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

int compare(char date1[], char date2[]) {

	int day1 = ((int)date1[0] - 48) * 10 + (int)date1[1] - 48;
	int month1 = ((int)date1[3] - 48) * 10 + (int)date1[4] - 48;
	int year1 = ((int)date1[6] - 48) * 1000 + ((int)date1[7] - 48) * 100 + ((int)date1[8] - 48) * 10 + (int)date1[9] - 48;

	int day2 = ((int)date2[0] - 48) * 10 + (int)date2[1] - 48;
	int month2 = ((int)date2[3] - 48) * 10 + (int)date2[4] - 48;
	int year2 = ((int)date2[6] - 48) * 1000 + ((int)date2[7] - 48) * 100 + ((int)date2[8] - 48) * 10 + (int)date2[9] - 48;

	//cout << day1 << " " << month1 << " " << year1 << endl;
	//cout << day2 << " " << month2 << " " << year2 << endl;

	if (year1 > year2) return 1;
	if (year1 < year2) return 2;
		
	if (month1 > month2) return 1;
	if (month1 < month2) return 2;

	if (day1 > day2) return 1;
	if (day1 < day2) return 2;
	
	return 0;
}

int main() {

	setlocale(LC_ALL, "Russian");

	char date1[11];
	char date2[11];

	gets_s(date1);
	gets_s(date2);

	int result = compare(date1, date2);

	if (result == 1) cout << date2 << " раньше, чем " << date1;
	if (result == 2) cout << date1 << " раньше, чем " << date2;
	if (result == 0) cout << "даты одинаковы";

	return 0;
}
