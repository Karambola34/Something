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
    bool isSorted = false;
    for (size_t i = 0; !isSorted && i < size - 1; i++) {
        isSorted = true;
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j]) {
                isSorted = false;

                swap(&a[j - 1], &a[j]);

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

void combSort(int *a, size_t size) {
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

int digit(int n, int constant, int N, int M) {
    return (n >> (N * constant) & (M - 1));
}

static void radixSort_(int *left, int *right, int size) {
    int k = (32 + size - 1) / size;

    int M = 1 << size;
    int newSize = right - left;
    int *b = (int *) malloc(sizeof(int) * newSize);
    int *c = (int *) malloc(sizeof(int) * M);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;
        for (int *j = left; j < right; j++)
            c[digit(*j, i, size, M)]++;
        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];
        for (int *j = right - 1; j >= left; j--)
            b[--c[digit(*j, i, size, M)]] = *j;
        int cur = 0;
        for (int *j = left; j < right; j++)
            *j = b[cur++];
    }

    free(b);
    free(c);
}

void radixSort(int *a, size_t n) {
    radixSort_(a, a + n, 8);
}