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

unsigned long long getBubbleSortNComps(int *a, size_t size) {
    unsigned long long nComps = 0;
    bool isSorted = false;
    for (size_t i = 0; ++nComps && !isSorted && i < size-1; i++) {
        isSorted = true;
        for (size_t j = size - 1; ++nComps && j > i; j--)
            if (++nComps && a[j - 1] > a[j]) {
                isSorted = false;

                swap(&a[j-1], &a[j]);
            }
    }

    return nComps;
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

unsigned long long getSelectionSortNComps(int *a, size_t size) {
    unsigned long long nComps = 0;
    for (int i = 0; ++nComps && i < size; i++) {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < size; j++)
            if (++nComps && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex)
            swap(&a[i], &a[minIndex]);
    }

    return nComps;
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

unsigned long long getInsertionSortNComps(int *a, size_t size) {
    unsigned long long nComps = 0;
    for (size_t i = 1; ++nComps && i < size; i++) {
        int t = a[i];
        int j = i;
        while (++nComps && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }

    return nComps;
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
unsigned long long getCombSortNComps(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    unsigned long long nComps = 2;
    while (++nComps && step > 1 || swapped) {
        if (++nComps && step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; ++nComps && j < size; ++i, ++j)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j]);

                swapped = 1;
            }
    }

    return nComps;
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

unsigned long long getShellSortNComps(int *a, size_t size) {
    unsigned long long nComps = 0;
    for (size_t step = size / 2; ++nComps && step > 0; step /= 2)
        for (size_t i = step; ++nComps && i < size; i++) {
            size_t j = i;
            while (++nComps && j >= step) {
                if (a[i] < a[j - step])
                    a[j] = a[j - step];
                j -= step;
            }

            a[j] = a[i];
        }
    return nComps;
}

int digit(int n, int constant, size_t size, int shiftAmount) {
    return (n >> (size * constant) & (shiftAmount - 1));
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
        int current = 0;
        for (int *j = left; j < right; j++)
            *j = b[current++];
    }

    free(b);
    free(c);
}

void radixSort(int *a, size_t size) {
    radixSort_(a, a + size, 8);
}

static unsigned long long getRadixSortNComps_(int *left, int *right, int size) {
    int lim = (32 + size - 1) / size;
    int shiftAmount = 1 << size;
    int newSize = right - left;
    int *b = (int *) malloc(sizeof(int) * newSize);
    int *c = (int *) malloc(sizeof(int) * shiftAmount);

    unsigned long long nComps = 0;
    for (int i = 0; ++nComps && i < lim; i++) {
        for (int j = 0; ++nComps && j < shiftAmount; j++)
            c[j] = 0;
        for (int *j = left; ++nComps && j < right; j++)
            c[digit(*j, i, size, shiftAmount)]++;
        for (int j = 1; ++nComps && j < shiftAmount; j++)
            c[j] += c[j - 1];
        for (int *j = right - 1; ++nComps && j >= left; j--)
            b[--c[digit(*j, i, size, shiftAmount)]] = *j;
        int current = 0;
        for (int *j = left; ++nComps && j < right; j++)
            *j = b[current++];
    }

    free(b);
    free(c);
}


unsigned long long getRadixSortNComps(int *a, const size_t size) {

    return getRadixSortNComps_(a, a + size, 8);
}