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
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j]) {

                swap(&a[j - 1], &a[j]);

                isSorted = 0;
            }
    }
}

void selectionSort(int *a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < size; j++)
            if (a[j] < a[min])
                min = j;

        swap(&a[i], &a[min]);
    }
}

void insertionSort(int *a, size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void combsort(int *a, size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {

                swap(&a[i], &a[j]);

                swapped = 1;
            }
    }
}

void shellSort(int *a, size_t size) {
    for (size_t step = size / 2; step > 0; step /= 2)
        for (size_t i = step; i < size; i++) {
            size_t j = i;
            while (j >= step) {
                if (a[i] < a[j - step])
                    a[j] = a[j - step];
                j -= step;
            }
            a[j] = a[i];
        }
}
