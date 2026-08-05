#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void StringFulling(char *s);

int main() {
    char *s1 = (char *)malloc(MAX * sizeof(char));
    char *s2 = (char *)malloc(MAX * sizeof(char));
    char *devider = (char *)malloc(MAX * sizeof(char));
    
    printf("\nВас приветствует строковый соединитель!\n");
    printf("Введите первую строку: ");
    StringFulling(s1);
    
    printf("Поздравляем! Ваша первая строка - %s\n", s1);
    printf("Введите вторую строку: ");
    StringFulling(s2);
    
    printf("Поздравляем! Ваша вторая строка - %s\n", s2);
    printf("Уточните, пожалуйста, чем разделить ваши строки (запятые, пробелы, иные символы): ");
    StringFulling(devider);

    size_t len1 = strnlen(s1, MAX);
    if (len1 < MAX - 1) {
        size_t avail = MAX - 1 - len1;
        strncat(s1, devider, avail);
    }

    len1 = strnlen(s1, MAX);
    if (len1 < MAX - 1) {
        size_t avail = MAX - 1 - len1;
        strncat(s1, s2, avail);
    }

    printf("Соединяем строки! Получили - %s\n", s1);

    free(s1);
    free(s2);
    free(devider);
    return 0;
}

void StringFulling(char *s) {
    char *copy_s = (char *)malloc(MAX * sizeof(char));
    int i;
    int len = 0;
    int end = 0;

    for (i = 0; i < MAX - 1; i++) {
        int ret = scanf("%c", &copy_s[i]);
        if (ret != 1) {
            end = 1;
        } else if (copy_s[i] == '\n') {
            end = 1;
        } else {
            s[len++] = copy_s[i];
        }
        if (end) {
            i = MAX - 1;
        }
    }
    s[len] = '\0';
    free(copy_s);
}
