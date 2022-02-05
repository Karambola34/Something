
#include "libs/data_structures/vector/vector.h"
#include <assert.h>
#include <stdio.h>

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 5);
    assert(v.capacity == 1);
    assert(v.data[0] == 5);
    assert(v.size == 1);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(2);
    v.size = 2;
    pushBack(&v, 5);
    assert(v.capacity == 4);
    assert(v.data[2] == 5);
    assert(v.size == 3);
    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}


void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    // последующие тесты
}

int main() {
    test();
    return 0;
}