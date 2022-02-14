//
// Created by averk on 11.02.2022.
//

#ifndef UNTITLED8_MATRIX_H
#define UNTITLED8_MATRIX_H

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// Размещает в динамической памяти матрицу размером nRows на nCols.
// Возвращает матрицу
matrix getMemMatrix(int nRows, int nCols);

// Размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.
// Возвращает указатель на нулевую матрицу
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// Освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix m);

// Освобождает память, выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices);

// Ввод матрицы m
void inputMatrix(matrix m);

// Ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

// Вывод матрицы m
void outputMatrix(matrix m);

// Вывод массива из nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(matrix *ms, int nMatrices);

// Обмен строк с порядковыми номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2);

// Обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2);

// Выполняет сортировку вставками строк матрицы m по неубыванию значения функции criteria
// применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

// Выполняет сортировку вставками столбцов матрицы m по неубыванию значения функции criteria
// применяемой для столбцов
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

// Возвращает значение ’истина’, если матрица m является квадратной,
// ложь – в противном случае
bool isSquareMatrix(matrix m);

// Возвращает значение ’истина’, если матрицы m1 и m2 равны,
// 'ложь' – в противном случае
bool twoMatricesEqual(matrix m1, matrix m2);

// Возвращает значение ’истина’, если матрица m является единичной,
// 'ложь' – в противном случае
bool isEMatrix(matrix m);

// Возвращает значение ’истина’, если матрица m является симметричной,
// 'ложь' – в противном случае
bool isSymmetricMatrix(matrix m);

// Транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix m);

// Возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m);

// Возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m);

// Возвращает матрицу, размера nRows на nCols, построенного из элементов массива a,
// размещенную в динамической памяти:
matrix createMatrixFromArray(const int *a, int nRows, int nCols);

// Возвращает указатель на нулевую матрицу массива из nMatrices матриц,
// размещенных в динамической памяти, построенных из элементов массива a
matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);

#endif //UNTITLED8_MATRIX_H
