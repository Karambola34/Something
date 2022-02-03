//
// Created by averk on 02.02.2022.
//
#ifndef UNTITLED8_VECTOR_H
#define UNTITLED8_VECTOR_H

#include <stdlib.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void shrinkToFit(vector *v);

#endif //UNTITLED8_VECTOR_H
