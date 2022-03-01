//
// Created by averk on 01.03.2022.
//

#include "removeNonLetters.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters () {
    char s [] = " Hi123 \n\t\t273#$^&";
    removeNonLetters(s) ;
    ASSERT_STRING("Hi123273#$^&",s);
}