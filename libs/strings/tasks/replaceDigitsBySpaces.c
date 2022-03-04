//
// Created by averk on 02.03.2022.
//

#include "replaceDigitsBySpaces.h"

#define ZERO_IN_CHAR 48

void replaceDigitsBySpaces(char *s) {
    char *recPtr = s;
    copy(s, getEndOfString(s) + 1, _stringBuffer);
    char *readPtr = _stringBuffer;
    while (*readPtr != '\0') {
        if (isdigit(*readPtr)) {
            int amountOfSpaces = *readPtr - ZERO_IN_CHAR;
            for (int i = 0; i < amountOfSpaces; i++) {
                *recPtr = ' ';
                recPtr++;
            }
        } else {
            *recPtr = *readPtr;
            recPtr++;
        }

        readPtr++;
    }
    *recPtr = '\0';
}

void test_replaceWithDigitsBySpaces() {
    char s[] = "1ds22fs0fsf";
    replaceDigitsBySpaces(s);
    ASSERT_STRING(" ds    fsfsf", s);
}

void test_replaceWithoutDigitsBySpaces() {
    char s[] = "ds fsfsf";
    replaceDigitsBySpaces(s);
    ASSERT_STRING("ds fsfsf", s);
}

void test_replaceEmpty() {
    char s[] = "";
    replaceDigitsBySpaces(s);
    ASSERT_STRING("", s);
}

void test_replaceDigitsBySpaces() {
    test_replaceWithDigitsBySpaces();
    test_replaceWithoutDigitsBySpaces();
    test_replaceEmpty();
}