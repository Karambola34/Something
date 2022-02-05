
#include "libs/data_structures/vector/vector.h"
#include <assert.h>


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

void test_atVector_notEmptyVector() {
    vector v = createVector(4);
    pushBack(&v, 5);
    pushBack(&v, 8);
    assert(&v.data[1] == atVector(&v, 1));
    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(4);
    pushBack(&v, 0);
    pushBack(&v, 4);
    pushBack(&v, 5);
    pushBack(&v, 1);
    assert(&v.data[3] == atVector(&v, 3));
    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 8);
    assert(back(&v) == &v.data[0]);
    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 8);
    assert(front(&v) == &v.data[0]);
    deleteVector(&v);
}


void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
    // последующие тесты
}

int main() {
    test();
    return 0;
}