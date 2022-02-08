//
// Created by averk on 02.02.2022.
//

#include "vector.h"

vector createVector(size_t n) {
    int *pointerToBeginning = (int *) malloc(sizeof(int) * n);
    if (pointerToBeginning == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }

    return (vector) {pointerToBeginning, 0, n};
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
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return !v->size;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isEmpty(v))
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }
    v->size--;
}

int *atVector(vector *v, size_t index) {
    if (index > v->size || index < 0 || isEmpty(v)) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }

    return &v->data[index];
}

int *back(vector *v) {
    return atVector(v, 0);
}

int *front(vector *v) {
    return atVector(v, v->size - 1);
}