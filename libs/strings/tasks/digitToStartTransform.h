//
// Created by averk on 01.03.2022.
//

#ifndef UNTITLED8_DIGITTOSTARTTRANSFORM_H
#define UNTITLED8_DIGITTOSTARTTRANSFORM_H

#include  "../string_.h"

// преобразовывает строку таким образом, чтобы цифры каждого слова word были перенесены в конец слова,
// а буквы – в начало слова, без изменения порядка следования
void digitToStartLettersFirstDigitsSecond(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isalpha);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}


// считывает все слова в строке s
void digitToStartForAllWords(char *s) {
    char *beginSearch = s;
    WordDescriptor words;
    while (getWord(beginSearch, &words)) {
        digitToStartLettersFirstDigitsSecond(words);

        beginSearch = words.end;
    }
}

void test_digitToStartNotEmpty() {
    char s[] = "A32BC1 W09MWOO7";
    digitToStartForAllWords(s);

    ASSERT_STRING("ABC321 WMWOO097", s);
}

void test_digitToStartEmpty() {
    char s[] = "";
    digitToStartForAllWords(s);

    ASSERT_STRING("", s);
}

void test_digitToStartLettersFirstDigitsSecond() {
    test_digitToStartEmpty();
    test_digitToStartNotEmpty();
}


#endif //UNTITLED8_DIGITTOSTARTTRANSFORM_H
