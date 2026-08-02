#include <math.h>
#include <stdio.h>

void decision(float a, float b, float c);

int main() {
    float a, b, c;
    printf("\nДобрый день! Меня зовут Дискр, я решу Ваше квадратное уравнение!\n");
    printf("Введите коэффициент a: ");
    if (scanf("%f", &a) != 1) {
        printf("\nВведены некорректные данные\n");
        return 1;
    }
    if (a == 0) {
        printf("\nНе является квадратным уравнением\n");
        return 1;
    }
    printf("\nВведите коэффициент b: ");
    if (scanf("%f", &b) != 1) {
        printf("\nВведены некорректные данные\n");
        return 1;
    }
    printf("\nВведите свободный член c: ");
    if (scanf("%f", &c) != 1) {
        printf("\nВведены некорректные данные\n");
        return 1;
    }
    decision(a, b, c);
    return 0;
}

void decision(float a, float b, float c) {
    double discriminant;
    double x, x1, x2;
    discriminant = (double)b * b - 4.0 * a * c;
    printf("\nДискриминант квадратного уравнения равен %.2f\n", discriminant);
    if (discriminant < 0) {
        printf("\nНет действительных корней\n");
    } else if (discriminant == 0) {
        x = -b / (2.0 * a);
        printf("\nx = %.2f\n", x);
    } else {
        x1 = (-b + sqrt(discriminant)) / (2.0 * a);
        x2 = (-b - sqrt(discriminant)) / (2.0 * a);
        printf("\nx1 = %.2f; x2 = %.2f\n", x1, x2);
    }
}
