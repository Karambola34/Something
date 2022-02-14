
#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>


void swapMinMax(matrix m) {
    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);
}

void test_swapRowsOfMinMax1() {
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

void test_swapRowsOfMinMax2() {
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

void test() {
    test_swapRowsOfMinMax();

}

int main() {
    test();

    return 0;
