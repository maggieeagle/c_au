#define _USE_MATH_DEFINES

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

//[2.5,4], [2,4]
double f1(double x) {
	return sin(x-3) * pow(M_E,x);
}


//[0.2,1.2],[1.4,2.6]
double f2(double x) {
	return log(x) * cos(x);
}

double der1(double x, int f) {
	if (f == 1) return (f1(x + 0.1) - f1(x)) / 0.1;
	return (f2(x + 0.1) - f2(x)) / 0.1;
}

double der2(double x, int f) {
	return (der1(x + 0.1, f) - der1(x, f)) / 0.1;
}


double tangentMethod(double eps, double first, double last, int f) {

	double mid, k, b, x, x0;
	bool sign = 0;

	if (f == 1){

		//f(x0) * f''(x0) > 0
		if (f1(first) * der2(first, f) > 0) x0 = first;
		else x0 = last;

		while (abs(f1(x0)) > eps) {

			k = der1(x0, f); //y = k * x + b
			b = f1(x0) - k * x0;
			x0 = (-b) / k;
		}
	}
	else {
		//f(x0) * f''(x0) > 0
		if (f2(first) * der2(first, f) > 0) x0 = first;
		else x0 = last;

		while (abs(f2(x0)) > eps) {

			//cout << "x0 = " << x0 << endl;

			k = der1(x0, f); //y = k * x + b
			b = f2(x0) - k * x0;
			x0 = (-b) / k;
		}
	}

	//cout << "x0 = " << x0 << endl;
	//cout << "f2(x0) = " << f2(x0) << endl;

	x0 = roundNnum(x0, eps);

	return x0;
}


int main() {

	setlocale(LC_ALL, "Russian");

	double eps, first, last;
	int f;

	cout << "Выберите функцию: " << endl << "(1) sin(x-3)*e^x" << endl
		<< "(2) ln(x)*cos(x)" << endl;
	cin >> f;
	cout << "Введите точность:" << endl;
	cin >> eps;
	cout << "Введите начало интервала:" << endl;
	cin >> first;
	cout << "Введите конец интервала:" << endl;
	cin >> last;

	double result = tangentMethod(eps, first, last, f);

	cout << "Корнем уравнения ";
	if (f == 1) cout << "sin(x-3)*e^x=0";
	else cout << "ln(x)*cos(x)=0";
	cout << " на интервале(" << first << ';' << last << ") является " << result;
	

	return 0;
}
