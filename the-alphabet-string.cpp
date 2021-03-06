#include <stdio.h>
#include <iostream>

using namespace std;

const char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
const char reverseAlphabet[27] = "zyxwvutsrqponmlkjihgfedcba";

bool isLetter(char ch) {
	bool flag = 0;
	for (int i = 0; i < 26; i++) {
		if (ch == alphabet[i]) flag = 1;
	}
	if (flag == 1) return 1;
	return 0;
}

bool check(char *input) {
	if (isLetter(input[0]) && input[1] == '-' && isLetter(input[2])) return 1;
	return 0;
}

bool checkReverse(char first, char last) {
	int indexf, indexl;
	for (int i = 0; i < 26; i++) {
		if (first == alphabet[i]) indexf = i;
		if (last == alphabet[i]) indexl = i;
	}

	if (first < last) return 1;
	return 0;
}

int main() {

	setlocale(LC_ALL, "Russian");

	char input[4] = { 0 }, input2[100] = { 0 };

	while (true) {
		gets_s(input2);
		if (strlen(input2) == 3 && check(input2)) break;
		else cout << "Неверный формат ввода, попробуйте еще раз:";
	}

	for (int i = 0; i < 4; i++) input[i] = input2[i];

	char first = input[0];
	char last = input[2];

	bool reverse = checkReverse(first, last);

	if (reverse) {
		int i = 0;
		for (; first != alphabet[i]; i++);
		for (; last != alphabet[i]; i++) cout << alphabet[i];
		cout << alphabet[i];
	}
	else {
		int i = 0;
		for (; first != reverseAlphabet[i]; i++);
		for (; last != reverseAlphabet[i]; i++) cout << reverseAlphabet[i];
		cout << reverseAlphabet[i];
	}

	return 0;
}
