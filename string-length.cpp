#include <stdio.h>
#include <iostream>

int strlen2(char str[]) {
	int count = 0;
	for (int i = 0; str[i] != '\0' && i < 100; i++) {
		count++;
	}
	return count;
}

int main(){

	char str[100];

	gets_s(str);
	//std::cout << str;
	std::cout << strlen(str) << std::endl;
	std::cout << strlen2(str);

	return 0;
}
