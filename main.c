
#include "libs/data_structures/matrix/matrix.h"
#include <math.h>
#include <limits.h>

// Обмен строк, в которых находятся максимальный и минимальный элементы матрицы m
void swapMinMax(matrix m) {
    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);
}

// Возвращает максимальное значение в массиве a размера n
int getMax(int *a, int n) {
    int maxValue = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > maxValue)
            maxValue = a[i];

    return maxValue;
}

// Упорядочивает строки матрицы m по неубыванию наибольших элементов строк
void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

// Возвращает минимальное значение в массиве a размера n
int getMin(int *a, int n) {
    int minValue = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] < minValue)
            minValue = a[i];

    return minValue;
}

// Упорядочивает строки матрицы m по неубыванию минимальных элементов столбцов
void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

// Возвращает произведение матриц m1 и m2
matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);
    matrix m = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            m.values[i][j] = 0;
            for (int k = 0; k < m2.nRows; k++)
                m.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return m;
}

// Заменяет матрицу m ее квадратом, если она симметрична
void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}


// Возвращает сумму элементов массива a размера n
long long getSum(const int *const a, int n) {
    long long sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

// Возвращает значение 'истина', если все элементы массива a размера n являются уникальными,
// иначе возвращает значение 'ложь'
bool isUnique(const long long *const a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;

    return true;
}

// Транспонирует матрицу m, если среди сумм элементов строк матрицы нет равных
void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sumArray[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        sumArray[i] = getSum(m.values[i], m.nCols);
    if (isUnique(sumArray, m.nRows))
        transposeSquareMatrix(m);
}


// Возвращает значение 'истина', если матрицы m1 и m2 взаимно обратные
// иначе возвращает значение 'ложь'
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isEMatrix(mulMatrices(m1, m2));
}

// Возвращает максимальное значение из чисел a и b
int max(int a, int b) {
    return a > b ? a : b;
}

// Возвращает сумму максимальных элементов псевдодиагоналей матрицы m
long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int sizeOfPseudoDiagonal = m.nCols + m.nRows - 1;
    int arrayOfMaxesOfPseudoDiagonals[sizeOfPseudoDiagonal];
    for (int i = 0; i < sizeOfPseudoDiagonal; i++)
        arrayOfMaxesOfPseudoDiagonals[i] = INT_MIN;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            if (i != j) {
                int k = j - i + m.nRows - 1;
                arrayOfMaxesOfPseudoDiagonals[k] = max(m.values[i][j], arrayOfMaxesOfPseudoDiagonals[k]);
            }
        }
    arrayOfMaxesOfPseudoDiagonals[m.nRows - 1] = 0;
    return getSum(arrayOfMaxesOfPseudoDiagonals, sizeOfPseudoDiagonal);
}

// Возвращает минимальный элемент матрицы m в выделенной области
int getMinInArea(matrix m) {
    position maxElementPosition = getMaxValuePos(m);
    int minElement = m.values[maxElementPosition.rowIndex][maxElementPosition.colIndex];
    int left = maxElementPosition.colIndex;
    int right = left;
    for (int i = maxElementPosition.rowIndex - 1; i >= 0; i--) {
        if (left)
            left--;
        if (right != m.nCols - 1)
            right++;
        int minElementInArray = getMin(m.values[i] + left, right - left + 1);
        if (minElementInArray < minElement)
            minElement = minElementInArray;
    }

    return minElement;
}

// Возвращает дистанцию от точки массива a размера n до начала координат
float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; i++)
        distance += (float) a[i] * a[i];

    return sqrtf(distance);
}

// Выполняет сортировку вставками строк матрицы m по неубыванию значения функции criteria
// применяемой для строк
void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float rowArray[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        rowArray[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 1; i < m.nRows; i++) {
        float t = rowArray[i];
        int j = i;
        while (j > 0 && rowArray[j - 1] > t) {
            rowArray[j] = rowArray[j - 1];
            swapRows(m, j - 1, j);
            j--;
        }
        rowArray[j] = t;
    }
}

// Упорядочивает точки матрицы m по неубыванию их расстояний до начала координат
void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const int *) pa;
    int arg2 = *(const int *) pb;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

// Возвращает число неуникальных элементов массива a размера
int countNUnique(long long *a, int n) {
    long long lastSavedValue = a[0] - 1;
    long long nUnique = 0;
    for (size_t i = 1; i < n; i++)
        if (a[i] == a[i - 1] && a[i] != lastSavedValue) {
            nUnique++;
            lastSavedValue = a[i];
        }

    return nUnique;
}

// Возвращает количество классов эквивалентных строк матрицы m
int countEqClassesByRowsSum(matrix m) {
    long long a[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        long long sum = 0;
        for (int j = 0; j < m.nCols; j++)
            sum += m.values[i][j];
        a[i] = sum;
    }
    qsort(a, m.nRows, sizeof(long long), cmp_long_long);

    return countNUnique(a, m.nRows);
}

// Возвращает количество "особых" элементов матрицы m
int getNSpecialElement(matrix m) {
    int countUnique = 0;
    for (int j = 0; j < m.nCols; j++) {
        int maxValue = m.values[0][j];
        int sum = m.values[0][j];
        for (int i = 1; i < m.nRows; i++) {
            sum += m.values[i][j];
            if (m.values[i][j] > maxValue)
                maxValue = m.values[i][j];
        }
        if (maxValue > sum - maxValue)
            countUnique++;
    }

    return countUnique;
}

// Возвращает позицию первого минимального элемента матрицы m
position getLeftMin(matrix m) {
    int minValue = m.values[0][0];
    position minValuePos = {0, 0};
    for (int j = 0; j < m.nCols; j++)
        for (int i = 0; i < m.nRows; i++)
            if (m.values[i][j] < minValue) {
                minValue = m.values[i][j];
                minValuePos = (position) {i, j};
            }

    return minValuePos;
}

// Заменяет предпоследнюю строку матрицы m размера n первым из столбцов,
// в котором находится минимальный элемент матрицы
void swapPenultimateRow(matrix m, int n) {
    int arrayOfMinCol[n];
    int minColIndex = getLeftMin(m).colIndex;
    for (int i = 0; i < n; i++)
        arrayOfMinCol[i] = m.values[i][minColIndex];
    for (int j = 0; j < n; j++)
        m.values[n - 2][j] = arrayOfMinCol[j];
}

// Возвращает значение 'истина', если массив a размера n отсортирован по неубыванию,
// иначе возвращает значение 'ложь'
bool isNonDescendingSorted(const int *const a, int n) {
    if (n <= 1)
        return false;
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;

    return true;
}

// Возвращает значение 'истина', если все строки матрицы m отсортированы по неубыванию,
// иначе возвращает значение 'ложь'
bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;

    return true;
}

// Возвращает число матриц в массиве матриц ms размера nMatrix,
// строки которых упорядочены по неубыванию
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; i++)
        if (hasAllNonDescendingRows(ms[i]))
            count++;

    return count;
}

// Возвращает количество вхождений числа value в массив a размера n
int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            count++;

    return count;
}

// Возвращает число нулевых строк в матрице m
int countZeroRows(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; i++) {
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            count++;
    }

    return count;
}


// Выводит матрицы массива матриц ms размера nMatrix, имеющие наибольшее число нулевых строк
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int arrayOfNumberOfZeroRows[nMatrix];
    for (int i = 0; i < nMatrix; i++)
        arrayOfNumberOfZeroRows[i] = countZeroRows(ms[i]);
    int maxNumberOfZero = getMax(arrayOfNumberOfZeroRows, nMatrix);
    for (int i = 0; i < nMatrix; i++)
        if (arrayOfNumberOfZeroRows[i] == maxNumberOfZero)
            outputMatrix(ms[i]);
}

// Возвращает норму матрицы m
int getNorm(matrix m) {
    int norm = abs(m.values[0][0]);
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            int value = abs(m.values[i][j]);
            if (value > norm)
                norm = value;
        }

    return norm;
}

// Выводит матрицы массива матриц ms размера nMatrix, с наименьшей нормой
void printMatrixWithMinNorm(matrix *ms, int nMatrix) {
    int arrayOfNumberOfNorms[nMatrix];
    for (int i = 0; i < nMatrix; i++)
        arrayOfNumberOfNorms[i] = getNorm(ms[i]);
    int minNumberOfNorm = getMin(arrayOfNumberOfNorms, nMatrix);
    for (int i = 0; i < nMatrix; i++)
        if (arrayOfNumberOfNorms[i] == minNumberOfNorm)
            outputMatrix(ms[i]);
}

//Тесты

void test_swapRows() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);
    swapRows(m1, 0, 1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 5, 6,
                    1, 2, 3,
                    7, 8, 9,
            },
            3, 3);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapColumns() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);
    swapColumns(m1, 0, 1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 1, 3,
                    5, 4, 6,
                    8, 7, 9,
            },
            3, 3);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 6,
                    4, 5, 3,
                    7, 8, 9,
            },
            3, 3);
    insertionSortRowsMatrixByRowCriteria(m1, getMax);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 5, 3,
                    1, 2, 6,
                    7, 8, 9,
            },
            3, 3);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_insertionSortColsMatrixByColCriteria() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 6,
                    4, 5, 3,
                    8, 9, 7,
            },
            3, 3);
    insertionSortColsMatrixByColCriteria(m1, getMax);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    6, 1, 2,
                    3, 4, 5,
                    7, 8, 9,
            },
            3, 3);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

static void test_squareMatrix1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 1, 2,
                    3, 4, 5,
                    7, 8, 9,
            },
            3, 3);
    assert(isSquareMatrix(m));

    freeMemMatrix(m);
}

static void test_notSquareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 4, 5,
                    7, 8, 9,
            },
            2, 3);
    assert(!isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_isSquareMatrix() {
    test_squareMatrix1();
    test_notSquareMatrix();
}

static void test_twoMatricesAreEqual() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    4, 5,
                    7, 8,
            },
            2, 2);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 5,
                    7, 8,
            },
            2, 2);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

static void test_twoMatricesAreNotEqual() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    4, 7,
                    7, 8,
            },
            2, 2);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 5,
                    7, 8,
            },
            2, 2);
    assert(!twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_twoMatricesEqual() {
    test_twoMatricesAreEqual();
    test_twoMatricesAreNotEqual();
}

static void test_eMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1,
            },
            2, 2);
    assert(isEMatrix(m));

    freeMemMatrix(m);
}

static void test_notEMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1,
                    0, 1,
            },
            2, 2);
    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix() {
    test_eMatrix();
    test_notEMatrix();
}

static void test_symmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    5, 1,
                    1, 1,
            },
            2, 2);
    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

static void test_notSymmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    5, 1,
                    6, 1,
            },
            2, 2);
    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix() {
    test_symmetricMatrix();
    test_notSymmetricMatrix();
}

void test_transposeSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    5, 1,
                    6, 1,
            },
            2, 2);
    transposeSquareMatrix(m1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 6,
                    1, 1,
            },
            2, 2);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);
    position x = getMinValuePos(m);
    assert(x.rowIndex == 0 && x.colIndex == 0);

    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);
    position x = getMaxValuePos(m);
    assert(x.rowIndex == 2 && x.colIndex == 2);

    freeMemMatrix(m);
}

static void test_swapRowsOfMinMax1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);
    swapMinMax(m1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    4, 5, 6,
                    1, 2, 3,
            },
            3, 3);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

static void test_swapRowsOfMinMax2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 9, 6,
                    7, 8, 5,
            },
            3, 3);
    swapMinMax(m1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 9, 6,
                    1, 2, 3,
                    7, 8, 5,
            },
            3, 3);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapRowsOfMinMax() {
    test_swapRowsOfMinMax1();
    test_swapRowsOfMinMax2();
}

void test_sortRowsByMinElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3,
            },
            3, 3);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1,
            },
            3, 3);
    sortRowsByMinElement(m1);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortColsByMinElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3,
            },
            3, 6);
    sortColsByMinElement(m1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4,
            },
            3, 6);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

static void test_squareOfMatrixIfSymmetric() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 9,
                    2, 9, 3,
            },
            3, 3);
    getSquareOfMatrixIfSymmetric(&m1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    54, 33, 29,
                    33, 146, 101,
                    29, 101, 94,
            },
            3, 3);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

static void test_squareOfMatrixIfNotSymmetric() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);
    getSquareOfMatrixIfSymmetric(&m1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric() {
    test_squareOfMatrixIfSymmetric();
    test_squareOfMatrixIfNotSymmetric();
}

static void test_ifMatrixHasNotEqualSumOfRows() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 2, 4,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(m1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 4, 7,
                    2, 5, 8,
                    4, 6, 9,
            },
            3, 3);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

static void test_ifMatrixHasEqualSumOfRows() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 2, 2,
                    7, 8, 9,
            },
            3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(m1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 2, 2,
                    7, 8, 9,
            },
            3, 3);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);

}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_ifMatrixHasNotEqualSumOfRows();
    test_ifMatrixHasEqualSumOfRows();
}

static void test_MutuallyInverseMatrices() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3,
            },
            3, 3);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, -1, 1,
                    -38, 41, -34,
                    27, -29, 24,
            },
            3, 3);
    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

static void test_notMutuallyInverseMatrices2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3,
            },
            3, 3);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3,
            },
            3, 3);
    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices() {
    test_MutuallyInverseMatrices();
    test_notMutuallyInverseMatrices2();
}

static void test_findSumOfMaxesOfPseudoDiagonal1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 2,
                    4, 3, 3,
                    2, 5, 1,
                    8, 2, 7,
                    6, 1, 4,
                    4, 8, 3,
            },
            6, 3);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 38);

    freeMemMatrix(m);
}

static void test_findSumOfMaxesOfPseudoDiagonal2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3,
            },
            3, 6);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 35);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal1();
    test_findSumOfMaxesOfPseudoDiagonal2();
}

static void test_getMinInArea1() {
    matrix m = createMatrixFromArray(
            (int[]) {10, 7, 5, 6,
                     3, 11, 8, 9,
                     4, 1, 12, 2,},
            3, 4);
    assert(getMinInArea(m) == 5);

    freeMemMatrix(m);
}

static void test_getMinInArea2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1,
            },
            3, 4);
    assert(getMinInArea(m) == 6);

    freeMemMatrix(m);
}

void test_getMinInArea() {
    test_getMinInArea1();
    test_getMinInArea2();
}

void test_sortByDistances() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 5, 6,
                    4, 5, 6,
                    10, 0, 0,
            },
            3, 3);
    sortByDistances(m1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 5, 6,
                    10, 0, 0,
                    9, 5, 6,
            },
            3, 3);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_countEqClassesByRowsSum() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0,
            },
            6, 2);
    assert(countEqClassesByRowsSum(m) == 3);

    freeMemMatrix(m);
}

void test_isSpecialElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2,
            },
            3, 4);
    getNSpecialElement(m);
    assert(getNSpecialElement(m) == 2);

    freeMemMatrix(m);
}

void test_NoSpecialElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 6,
                    2, 2, 1, 2,
            },
            3, 4);
    getNSpecialElement(m);
    assert(getNSpecialElement(m) == 0);

    freeMemMatrix(m);
}

void test_getNSpecialElement() {
    test_isSpecialElement();
    test_NoSpecialElement();
}

void test_swapPenultimateRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 4,
                    4, 5, 6, 8,
                    7, 8, 1, 10,
                    5, 0, 6, 8,
            },
            4, 4);
    swapPenultimateRow(m1, m1.nRows);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 4,
                    4, 5, 6, 8,
                    2, 5, 8, 0,
                    5, 0, 6, 8,
            },
            4, 4);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_countNonDescendingRowsMatrices() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9,}, 4, 2, 2);
    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_countZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0, 0,
                    0, 0, 0, 0,
                    5, 0, 6, 8,
            },
            3, 4);
    assert(countZeroRows(m) == 2);

    freeMemMatrix(m);
}

void test_getNorm() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 5, 6,
                    4, 5, 6,
                    -10, 8, 0,
                    -100, 7, 26,
            },
            4, 3);
    assert(getNorm(m) == 100);

    freeMemMatrix(m);
}


void test() {
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_twoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
    test_swapRowsOfMinMax();
    test_sortRowsByMinElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistances();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
    test_countZeroRows();
    test_getNorm();
}

int main() {
    test();

}