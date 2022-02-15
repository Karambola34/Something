
#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>


void swapMinMax(matrix m) {
    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);
}

int getMax(int *a, int n) {
    int maxValue = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > maxValue)
            maxValue = a[i];
    return maxValue;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int getMin(int *a, int n) {
    int minValue = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] < minValue)
            minValue = a[i];
    return minValue;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

matrix mulMatrices(matrix m1, matrix m2) {
    matrix m = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            m.values[i][j] = 0;
            for (int k = 0; k < m2.nRows; k++)
                m.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    return m;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

//Тесты
static void test_swapRowsOfMinMax1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);
    swapMinMax(m);
    assert(m.values[0][0] == 7 && m.values[2][0] == 1);
}

static void test_swapRowsOfMinMax2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 9, 6,
                    7, 8, 5,
            },
            3, 3);
    swapMinMax(m);
    assert(m.values[0][0] == 4 && m.values[1][0] == 1);
}

void test_swapRowsOfMinMax() {
    test_swapRowsOfMinMax1();
    test_swapRowsOfMinMax2();
}

void test_sortRowsByMinElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3,
            },
            3, 3);
    sortRowsByMinElement(m);
    assert(m.values[0][0] == 3 && m.values[1][0] == 7 && m.values[2][1] == 8);
}

void test_sortColsByMinElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3
            },
            3, 6);
    sortColsByMinElement(m);
    assert(m.values[2][0] == 1 && m.values[1][1] == 1 && m.values[1][2] == 2 && m.values[1][3] == 2 &&
           m.values[0][4] == 3 && m.values[0][5] == 4);
}

static void test_getSquareOfMatrixIfSymmetric1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 9,
                    2, 9, 3,
            },
            3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    assert(m.values[0][0] == 54 && m.values[0][1] == 33 && m.values[0][2] == 29 && m.values[1][1] == 146 &&
           m.values[2][2] == 94 && m.values[2][1] == 101);
}

static void test_getSquareOfMatrixIfSymmetric2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    assert(m.values[0][0] == 1 && m.values[0][1] == 2 && m.values[0][2] == 3 && m.values[1][0] == 4 &&
           m.values[1][1] == 5 && m.values[1][2] == 6&&m.values[2][0]==7&&m.values[2][1]==8&&m.values[2][2]==9);
}

void test_getSquareOfMatrixIfSymmetric(){
    test_getSquareOfMatrixIfSymmetric1();
    test_getSquareOfMatrixIfSymmetric2();
}
void test() {
    test_swapRowsOfMinMax();
    test_sortRowsByMinElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();

}

int main() {
    test();

    return 0;
}