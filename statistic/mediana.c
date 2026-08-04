#include "mediana.h"
#include "sort.h"

float mediana(int number, int *data) {
    float result;
    sort(number, data);
    if (number % 2) {
        result = data[number / 2];
    } else {
        result = (float)(data[number / 2] + data[number / 2 - 1]) / 2.0;
    }
    return result;
}
