//
// Created by averk on 08.03.2022.
//

#ifndef UNTITLED8_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define UNTITLED8_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include  "../string_.h"


typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;



// возвращает значение EMPTY_STRING в строке s нет слов,
// FIRST_WORD_WITH_A если слово содержащее "a" первое, WORD_FOUND если перед словом, содержащим "a"
// есть другое слово, начинающееся с beginWordBefore и заканчивающееся endWordBefore,
// NOT_FOUND_A_WORD_WITH_A если слов, содержащих "a", нет
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore,
                                                               char **endWordBefore) {
    WordDescriptor lastWord;
    char *begin = s;
    if (!getWord(begin, &lastWord))
        return EMPTY_STRING;
    if (find(lastWord.begin, lastWord.end, 'a') != lastWord.end ||
        find(lastWord.begin, lastWord.end, 'A') != lastWord.end)
        return FIRST_WORD_WITH_A;
    begin = lastWord.end;
    WordDescriptor word;
    while (getWord(begin, &word)) {
        if (find(word.begin, word.end, 'a') != word.end || find(word.begin, word.end, 'A') != word.end) {
            *beginWordBefore = lastWord.begin;
            *endWordBefore = lastWord.end;
            return WORD_FOUND;
        }
        lastWord = word;
        begin = word.end;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

// выводит слово строки s, предшествующее первому из слов, содержащих букву "а"
void printWordBeforeFirstWordWithA(char *s) {
    char *beginWordBefore, *endWordBefore;
    if (getWordBeforeFirstWordWithA(s, &beginWordBefore, &endWordBefore) == WORD_FOUND) {
        *endWordBefore = '\0';
        printf("%s\n", beginWordBefore);
    }
}


void testAll_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &beginWord, &endWord)== EMPTY_STRING);

    char s2[] = " ABC";
    assert(getWordBeforeFirstWordWithA(s2, &beginWord, &endWord)== FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &beginWord, &endWord)== WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING ("BC", got);

    char s4[] = "B Q WE YR OW IUWR ";
    assert(getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) ==
           NOT_FOUND_A_WORD_WITH_A);
}

#endif //UNTITLED8_PRINTWORDBEFOREFIRSTWORDWITHA_H
