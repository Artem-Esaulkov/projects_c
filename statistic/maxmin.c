#include "maxmin.h"

int max(int number, int *data) {
    int result = data[0];
    for (int i = 1; i < number; i++) {
        if (data[i] > result) {
            result = data[i];
        }
    }
    return result;
}

int min(int number, int *data) {
    int result = data[0];
    for (int i = 1; i < number; i++) {
        if (data[i] < result) {
            result = data[i];
        }
    }
    return result;
}
