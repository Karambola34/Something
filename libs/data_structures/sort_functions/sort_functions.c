//
// Created by averk on 12.03.2022.
//

#include "sort_functions.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


void bubbleSort(int *a, size_t size) {
    int isSorted;
    for (size_t i = 0; i < size - 1 && isSorted; i++) {
        isSorted = 1;
        for (size_t j = size - 1; j > i; j --)
            if (a[j - 1] > a[j]) {
                swap(&a[j - 1], &a[j]);
                isSorted = 0;
            }
    }
}
