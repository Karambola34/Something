//
// Created by averk on 01.03.2022.
//

#include "removeExtraSpaces.h"

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

void test_removeExtraSpaces() {
    char s[] = " one two\n  three      4 ";
    removeExtraSpaces(s);
    ASSERT_STRING("one two\n three 4", s);
}