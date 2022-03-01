//
// Created by averk on 01.03.2022.
//

#include "digitToStartTransform.h"


void digitToStartLettersFirstDigitsSecond(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isalpha);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

void digitToStartForAllWords(char *s) {
    char *beginSearch = s;
    WordDescriptor words;
    while (getWord(beginSearch, &words)) {
        digitToStartLettersFirstDigitsSecond(words);

        beginSearch = words.end;
    }
}

void test_digitToStartLettersFirstDigitsSecond() {
    char s[] = "A32BC1 W09MWOO7";
    digitToStartForAllWords(s);

    ASSERT_STRING("ABC321 WMWOO097", s);
}