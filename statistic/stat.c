#include <stdio.h>
#include <stdlib.h>

#include "differ.h"
#include "maxmin.h"
#include "mediana.h"

int main() {
    int number;
    printf("\nДобрый день! Я Статик, занимаюсь расчетом статистических характеристик целых чисел в массиве данных\n");
    printf("Введите количество чисел в массиве: ");
    if (scanf("%d", &number) != 1 || number <= 0) {
        printf("\nВведены некорректные данные\n");
        return 1;
    }
    printf("Введите заданное количество чисел\n");
    int *data = (int *)malloc(number * sizeof(int));
    for (int i = 0; i < number; i++) {
        if (scanf("%d", &data[i]) != 1) {
            printf("\nВведены некорректные данные\n");
            free(data);
            return 1;
        }
    }
    printf("\nМаксимальное число массива - %d\n", max(number, data));
    printf("\nМинимальное число массива - %d\n", min(number, data));
    printf("\nРазмах массива - %d\n", differ(number, data));
    printf("\nМедиана массива - %.1f\n", mediana(number, data));
    free(data);
    return 0;
}
