#include "maxmin.h"
#include "differ.h"

int differ(int number, int *data) {
    return (max(number, data) - min(number, data));
}
