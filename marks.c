#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 256

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error");
        return 1;
    }
    char ch;
    int counter = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n' || ch == EOF) {
            counter++;
        }
    }
    printf("В этом классе %d учеников\n", counter);
    printf("Внимание! Вывожу фамилии троечников:\n");
    
    char **string_array = (char **)malloc(counter * sizeof(char *));
    if (string_array == NULL) {
        printf("Ошибка выделения памяти");
        return 1;
    }
    for (int i = 0; i < counter; i++) {
        string_array[i] = (char *)malloc(LEN * sizeof(char));
        if (string_array[i] == NULL) {
            printf("Ошибка выделения памяти");
            return 1;
        }
    }
    int true;
    ch = 'a';
    rewind(file);
    for (int i = 0; i < counter; i++) {
        true = 1;
        for (int j = 0; true; j++) {
            ch = fgetc(file);
            if (ch == '\n' || ch == EOF) {
                true = 0;
            } else {
                string_array[i][j] = ch;
            }
        }
    }
    int num = 0;
    for (int i = 0; i < counter; i++) {
        for (int j = 0; j < strlen(string_array[i]); j++) {
            if (string_array[i][j] == '3') {
                string_array[i][j - 2] = '\0';
                if (num) {
                    printf(", ");
                }
                printf("%s", string_array[i]);
                num++;
            }
        }
    }
    printf("\n");
    printf("Внимание! Вывожу фамилии хорошистов и отличников:\n");
    num = 0;
    for (int i = 0; i < counter; i++) {
        for (int j = 0; j < strlen(string_array[i]); j++) {
            if (string_array[i][j] == '4' || string_array[i][j] == '5') {
                string_array[i][j - 2] = '\0';
                if (num) {
                    printf(", ");
                }
                printf("%s", string_array[i]);
                num++;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < counter; i++) {
        free(string_array[i]);
    }
    fclose(file);
    free(string_array);
    return 0;
}
