#include <stdio.h>
#include <math.h>
#include <locale>

using namespace std;

#define PI 3.1415926

int check(float t1, float t2, float t3) {
    if (t1 + t2 > t3 && t1 + t3 > t2 && t2 + t3 > t1) return 1;
    return 0;
}

int main() {

    setlocale(LC_ALL, "Russian");

    float t1, t2, t3, p1, p2, r, p;

    printf("Длины сторон треугольника: \n");
    scanf("%f%f%f", &t1, &t2, &t3);
    //scanf("%f%f%f", &t1, &t2, &t3);
       // if (scanf("%f%f%f", &t1, &t2, &t3) != 3) printf("Не цифра! \n");
        //if (scanf("%f%f%f", &t1, &t2, &t3) == 0) {
           // printf("Введите три числа: \n");
           // while ( scanf("%f%f%f", &t1, &t2, &t3) == 0) {
           // }
       // }
            /*scanf("%f%f%f", &t1, &t2, &t3);

            while (scanf("%f%f%f", &t1, &t2, &t3) != 3) {
                printf("Недопустимое значение, попробуйте еще раз: ");
                while (getchar() != '\n'); // Чистим буфер
            }*/

    printf("Длины сторон прямоугольника: \n");
    scanf("%f%f", &p1, &p2);
    printf("Радиус окружности: \n");
    scanf("%f", &r);

    if (t1 > 0 && t2 > 0 && t3 > 0 && check(t1, t2, t3) == 1) {
        p = (t1 + t2 + t3) / 2;
        printf("Периметр треугольника = %.2f\n", 2 * p);
        printf("Площадь треугольника = %.2f\n", sqrt(p * (p - t1) * (p - t2) * (p - t3)));
    }
    else {
        printf("Треугольник с такими сторонами не существует!\n");
    }

    if (p1 > 0 && p2 > 0) {
        printf("Периметр прямоугольника = %.2f\n", 2 * (p1 + p2));
        printf("Площадь прямоугольника = %.2f\n", p1 * p2);
    }
    else {
        printf("Прямоугольник с такими сторонами не существует!\n");
    }

    if (r > 0) {
        printf("Длина окружности = %.2f\n", 2 * PI * r);
        printf("Площадь круга = %.2f\n", PI * r * r);
    }
    else {
        printf("Окружность с таким радиусом не существует!\n");
    }

    return 0;
}
