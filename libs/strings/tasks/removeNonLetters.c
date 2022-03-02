//
// Created by averk on 01.03.2022.
//

#include "removeNonLetters.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLettersNotEmpty () {
    char s [] = " Hi123 \n\t\t273#$^&";
    removeNonLetters(s) ;
    ASSERT_STRING("Hi123273#$^&",s);
}

void test_removeNonLettersEmpty () {
    char s [] = "";
    removeNonLetters(s) ;
    ASSERT_STRING("",s);
}

void test_removeNonLetters(){
    test_removeNonLettersEmpty();
    test_removeNonLettersNotEmpty();
}
