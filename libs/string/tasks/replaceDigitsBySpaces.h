//
// Created by averk on 02.03.2022.
//

#ifndef UNTITLED8_REPLACEDIGITSBYSPACES_H
#define UNTITLED8_REPLACEDIGITSBYSPACES_H

#include "../string_.h"

#define ZERO_IN_CHAR 48

//Преобразовает строку s, заменяя каждую цифру соответствующим ей числом пробелов
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

void test_replaceEmptyDigits() {
    char s[] = "";
    replaceDigitsBySpaces(s);
    ASSERT_STRING("", s);
}

void test_replaceDigitsBySpaces() {
    test_replaceWithDigitsBySpaces();
    test_replaceWithoutDigitsBySpaces();
    test_replaceEmptyDigits();
}


#endif //UNTITLED8_REPLACEDIGITSBYSPACES_H
