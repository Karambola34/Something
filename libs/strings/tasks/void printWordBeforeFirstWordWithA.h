//
// Created by averk on 08.03.2022.
//

#ifndef UNTITLED8_VOID_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define UNTITLED8_VOID_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include  "../string_.h"
#include <assert.h>

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

// выводит слово строки s, предшествующее первому из слов, содержащих букву "а"
void printWordBeforeFirstWordWithA(char *s);

// возвращает значение EMPTY_STRING в строке s нет слов,
// FIRST_WORD_WITH_A если слово содержащее "a" первое, WORD_FOUND если перед словом, содержащим "a"
// есть другое слово, начинающееся с beginWordBefore и заканчивающееся endWordBefore,
// NOT_FOUND_A_WORD_WITH_A если слов, содержащих "a", нет
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore,
                                                               char **endWordBefore);

void testAll_getWordBeforeFirstWordWithA();

#endif //UNTITLED8_VOID_PRINTWORDBEFOREFIRSTWORDWITHA_H
