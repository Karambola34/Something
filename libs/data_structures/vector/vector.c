//
// Created by averk on 02.02.2022.
//

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

vector createVector(size_t n) {
    vector v = {malloc(sizeof(int) * n), 0, n};
    if (v.data != NULL)
        return v;

    fprintf(stderr, "bad alloc ");
    exit(1);
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (!v->data) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->capacity = newCapacity;
    if (!newCapacity)
        v->data = NULL;
    if (v->size > newCapacity)
        v->size = newCapacity;

}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int *) realloc(v, sizeof(int) * v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}