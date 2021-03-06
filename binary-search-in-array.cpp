#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int steps = 0;

int sort(int* a, int size) {

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
		}
	}
	return 0;
}

int findelem(int num, int* a, int size) {

	sort(a, size);

	int first = 0, last = size - 1;
	int cur;
	while (last - first > 1) {
		steps++;
		cur = (first + last) / 2;
		//cout << first << ' ' << cur << ' ' << last << endl;
		if (a[cur] > num) last = cur;
		else first = cur;
	}

	if (a[first] == num) return first;
	if (a[first] == num) return cur;
	if (a[last] == num) return last;

	return -1;
}

int main() {

	setlocale(LC_ALL, "Russian");

	int n;
	cin >> n;

	int a[1000];
	int size = sizeof(a) / sizeof(int);


	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		a[i] = rand();
		cout << a[i] << ' ';
	}
	cout << endl;

	int elem = findelem(n, a, size);

	if (elem == -1) cout << "Массив не содержит элемент " << n;
	else cout << n << " = a[" << elem << ']' << endl << "Количество шагов: " << steps;

	return 0;
}
