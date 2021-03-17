#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	for (int i = 0; i < s2.length(); i++) {
		bool flag = 0;
		for (int j = 0; j < s1.length(); j++) {
			if (s2[i] == s1[j]) flag = 1;
		}
		if (flag == 0) cout << s2[i];
	}

	return 0;
}
