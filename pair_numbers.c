#include <stdio.h>

int main() {
    int min_number, max_number;
    printf("\nДобрый день! Вас приветствует генератор чётных чисел!\n");
    printf("Введите минимальную границу: ");
    if (scanf("%d", &min_number) != 1) {
        printf("\nВведены некорректные данные\n");
        return 1;
    }
    printf("\nВведите максимальную границу: ");
    if (scanf("%d", &max_number) != 1 || min_number > max_number) {
        printf("\nВведены некорректные данные\n");
        return 1;
    }
    int counter = 0;
    for (int i = min_number; i <= max_number; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
            counter++;
        }
    }
    if (!counter) {
        printf("Нет чётных чисел в заданном диапазоне");
    }
    printf("\n");
    return 0;
}
