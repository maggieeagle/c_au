#include <stdio.h>
#include <iostream>

using namespace std;

double roundNnum(double num, double eps) {
	int tmp = 0;
	for (double i = eps; i < 1; i *= 10, tmp++);
	tmp = pow(10, tmp);
	num = floor(num * tmp) / tmp;

	return num;
}

double f(double x) {
	return x * x + 6 * x - 3;
}

double binary_search(double eps, double first, double last) {

	double mid, f_mid;
	bool sign = 0;

	if (f(first) > f(last)) sign = 1;

	while (last - first > eps) {
		mid = (first + last) / 2;
		f_mid = f(mid);
		if (sign == 1) {
			if (f_mid > 0) first = mid;
			else last = mid;
		}
		else {
			if (f_mid > 0) last = mid;
			else first = mid;
		}
	}

	if (abs(f_mid) > eps * 10) return 0;

	mid = roundNnum(mid, eps);

	return mid;
}

int main() {

	setlocale(LC_ALL, "Russian");

	double eps, first, last;

	cout << "Введите точность:" << endl;
	cin >> eps;
	cout << "Введите начало интервала:" << endl;
	cin >> first;
	cout << "Введите конец интервала:" << endl;
	cin >> last;

	double result = binary_search(eps, first, last);

	if (result == 0) cout << "Уравнение не имеет корня на заданном интервале";
	else cout << "Корнем уравнения x ^ 2 + 6x - 3 = 0 на интервале (" << first << ';' << last << ") является " << result;

	return 0;
}
