//
// Created by averk on 07.03.2022.
//

#ifndef UNTITLED8_GETSTRINGWITHREVERSEDWORDS_H
#define UNTITLED8_GETSTRINGWITHREVERSEDWORDS_H

#include  "../string_.h"

// преобразовывает строку s, изменяя порядок следования слов в строке на обратный
void getStringWithReversedWords(char *s) {
    copy(s, getEndOfString(s), _stringBuffer);
    char *begin = _stringBuffer;
    char *recPtr = s;
    char *end = begin + strlen_(s);
    *end = '\0';
    getBagOfWords(&_bag, _stringBuffer);
    for (int i = _bag.size - 1; i >= 0; i--) {
        copy(_bag.words[i].begin, _bag.words[i].end, recPtr);
        recPtr += _bag.words[i].end - _bag.words[i].begin;
        *recPtr++ = ' ';
    }
    recPtr--;
    *recPtr = '\0';
}


void test_getStringWithWords() {
    char s[] = "i hope it works";
    getStringWithReversedWords(s);
    ASSERT_STRING("works it hope i", s);
}

void test_getStringWithoutWords() {
    char s[] = "";
    getStringWithReversedWords(s);
    ASSERT_STRING("", s);
}

void test_getStringWithReversedWords() {
    test_getStringWithWords();
    test_getStringWithoutWords();
}

#endif //UNTITLED8_GETSTRINGWITHREVERSEDWORDS_H
