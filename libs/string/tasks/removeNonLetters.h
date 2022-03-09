//
// Created by averk on 01.03.2022.
//

#ifndef UNTITLED8_REMOVENONLETTERS_H
#define UNTITLED8_REMOVENONLETTERS_H

#include  "../string_.h"

//удалить из строки все пробельные символы в строке s
void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLettersNotEmpty() {
    char s[] = " Hi123 \n\t\t273#$^&";
    removeNonLetters(s);
    ASSERT_STRING("Hi123273#$^&", s);
}

void test_removeNonLettersEmpty() {
    char s[] = "";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters() {
    test_removeNonLettersEmpty();
    test_removeNonLettersNotEmpty();
}


#endif //UNTITLED8_REMOVENONLETTERS_H
