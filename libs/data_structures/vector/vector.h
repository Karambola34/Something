//
// Created by averk on 02.02.2022.
//
#ifndef UNTITLED8_VECTOR_H
#define UNTITLED8_VECTOR_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

//возвращает структуру-дескриптор вектор v из n значений.
vector createVector(size_t n);

//изменяет количество памяти newCapacity, выделенное под хранение элементов вектора v
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из контейнера вектора v, но не освобождает выделенную память
void clear(vector *v);

//освобождает память вектора v, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору v
void deleteVector(vector *v);

//возвращает 1,если вектор v является пустым, иначе возвращает 0
bool isEmpty(vector *v);

//возвращает 1,если вектор v является полным, иначе возвращает 0
bool isFull(vector *v);

//возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в конец вектора v. Если вектор заполнен, увеличивает количество выделенной ему памяти в 2 раза
void pushBack(vector *v, int x);

//удаляет последний элемент из вектора v
void popBack(vector *v);

//возвращает указатель на index-ый элемент вектора v
int *atVector(vector *v, size_t index);

//возвращает указатель на последний элемент вектора v
int *back(vector *v);

//возвращает указатель на нулевой элемент вектора v.
int *front(vector *v);

#endif //UNTITLED8_VECTOR_H
