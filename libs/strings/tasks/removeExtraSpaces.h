//
// Created by averk on 01.03.2022.
//

#ifndef UNTITLED8_REMOVEEXTRASPACES_H
#define UNTITLED8_REMOVEEXTRASPACES_H

#include  "../string_.h"

//Сократить количество пробелов между словами данного предложения в строке s до одного
void removeExtraSpaces(char *s) {
    char *begin = s;
    char *copyStr = begin;
    int freeSpace = 0;
    while (*begin != '\0') {
        if (*begin != ' ' || freeSpace) {
            *copyStr = *begin;
            if (*begin == ' ')
                freeSpace = 0;
            else
                freeSpace = 1;
            copyStr++;
        }
        begin++;
    }
    if (!freeSpace)
        copyStr--;
    *copyStr = '\0';
}

void test_removeAreSpaces() {
    char s[] = " one two\n  three      4 ";
    removeExtraSpaces(s);
    ASSERT_STRING("one two\n three 4", s);
}

void test_removeNoSpaces() {
    char s[] = "onetwo\nthree4";
    removeExtraSpaces(s);
    ASSERT_STRING("onetwo\nthree4", s);
}

void test_removeEmpty() {
    char s[] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}

void test_removeExtraSpaces() {
    test_removeAreSpaces();
    test_removeNoSpaces();
    test_removeEmpty();
}

#endif //UNTITLED8_REMOVEEXTRASPACES_H
