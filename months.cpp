#include <stdio.h>
#include <iostream>

using namespace std;

bool isNumber(char *input) {
	int size = strlen(input);
	char f = input[0], s = '-1';
	if(size == 2) s = input[1];
	if(size == 1 && (f == '1' || f == '2' || f == '3' || f == '4' || f == '5' ||
		f == '6' || f == '7' || f == '8' || f == '9')) return 1;
	if (size == 2 && f == '1' && (s == '0' || s == '1' || s == '2')) return 1;
	return 0;
}

int main() {

	setlocale(LC_ALL, "Russian");

	char January[] = "January";
	char February[] = "February";
	char March[] = "March";
	char April[] = "April";
	char May[] = "May";
	char June[] = "June";
	char July[] = "July";
	char August[] = "August";
	char September[] = "September";
	char October[] = "October";
	char November[] = "November";
	char December[] = "December";
	char* month[12] = {January, February, March, April, May, June, July,
		August, September, October, November, December};

	char input[100] = { 0 };

	while (true) {
		gets_s(input);
		if (isNumber(input)) break;
		else cout << "Введите номер от 1 до 12:";
	}

	int n;

	int size = strlen(input);

	if (size == 1) n = input[0] - '0';
	else n = (input[0] - '0') * 10 + (input[1] - '0');

	cout << month[n - 1];

	return 0;
}
