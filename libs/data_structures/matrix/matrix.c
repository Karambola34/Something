//
// Created by averk on 11.02.2022.
//

#include "matrix.h"


matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            scanf("%d", &m.values[i][j]);
        }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        int t = m.values[i][j2];
        m.values[i][j2] = m.values[i][j1];
        m.values[i][j1] = t;

    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int rowArray[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        rowArray[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 1; i < m.nRows; i++) {
        int t = rowArray[i];
        int j = i;
        while (j > 0 && rowArray[j - 1] > t) {
            rowArray[j] = rowArray[j - 1];
            swapRows(m, j - 1, j);
            j--;
        }
        rowArray[j] = t;
    }
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int colArray[m.nCols];
    int auxiliaryColsArray[m.nRows];
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++) {
            auxiliaryColsArray[j] = m.values[j][i];
        }
        colArray[i] = criteria(auxiliaryColsArray, m.nRows);

    }
    for (int i = 1; i < m.nCols; i++) {
        int t = colArray[i];
        int j = i;
        while (j > 0 && colArray[j - 1] > t) {
            colArray[j] = colArray[j - 1];
            swapColumns(m, j, j - 1);
            j--;
        }
        colArray[j] = t;
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return 0;
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nRows; j++) {
            if (m1.values[i] != m2.values[j])
                return 0;
        }
    }

    return 1;
}

bool isEMatrix(matrix m) {
    isSquareMatrix(m);
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if ((i == j && m.values[i][j] != 1) || (i != j && m.values[i][j]))
                return 0;

    return 1;
}

bool isSymmetricMatrix(matrix m) {
    isSquareMatrix(m);
    size_t size = (m.nRows - 1) / 2 + 1;
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < m.nRows; j++)
            if (m.values[i][j] != m.values[j][i])
                return 0;

    return 1;
}

void transposeSquareMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < i; j++) {
            int toCopy = m.values[i][j];
            m.values[i][j] = m.values[j][i];
            m.values[j][i] = toCopy;
        }
}

position getMinValuePos(matrix m) {
    int minElement = m.values[0][0];
    position positionOfElement = {0, 0};
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if (minElement > m.values[i][j]) {
                minElement = m.values[i][j];
                positionOfElement = (position) {i, j};
            }

    return positionOfElement;
}

position getMaxValuePos(matrix m) {
    int maxElement = m.values[0][0];
    position positionOfElement = {0, 0};
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if (maxElement < m.values[i][j]) {
                maxElement = m.values[i][j];
                positionOfElement = (position) {i, j};
            }

    return positionOfElement;
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}


