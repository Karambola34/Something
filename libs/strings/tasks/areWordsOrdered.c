//
// Created by averk on 04.03.2022.
//

#include "areWordsOrdered.h"


int areWordsOrdered(char *s) {
    char *begin = s;
    WordDescriptor word;
    if (!getWord(s, &word))
        return 1;

    s = word.end;
    WordDescriptor lastWord = word;
    while (getWord(s, &word)) {
        if (areWordsEqual(lastWord, word) < 0)
            return 0;
        s = word.end;
        lastWord = word;
    }
    return 1;
}

void test_areWordsOrderedEmpty() {
    char s[] = "";
    assert(areWordsOrdered(s));
}

void test_wordsAreNotOrdered() {
    char s[] = "wapity woop";
    assert(!areWordsOrdered(s));
}

void test_wordsAreOrdered() {
    char s[] = "woop wapity";
    assert(areWordsOrdered(s));
}

void test_sameWordsAreOrdered() {
    char s[] = "wapity wapity";
    assert(areWordsOrdered(s));
}

void test_areWordsOrdered() {
    test_areWordsOrderedEmpty();
    test_wordsAreNotOrdered();
    test_wordsAreOrdered();
    test_sameWordsAreOrdered();
}