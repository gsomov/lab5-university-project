#include "array_lib.h"

void replace_positive_with_zero_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            arr[i] = 0;
        }
    }
}