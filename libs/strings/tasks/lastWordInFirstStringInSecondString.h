//
// Created by averk on 08.03.2022.
//

#ifndef UNTITLED8_LASTWORDINFIRSTSTRINGINSECONDSTRING_H
#define UNTITLED8_LASTWORDINFIRSTSTRINGINSECONDSTRING_H

#include  "../string_.h"

// возвращает последнее из слов первой строки s1, которое есть во второй строке s2
WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2);

// переводит слово word в строку destination
void wordDescriptorToString(WordDescriptor word, char *destination);

void test_lastWordInFirstStringInSecondString();


#endif //UNTITLED8_LASTWORDINFIRSTSTRINGINSECONDSTRING_H
