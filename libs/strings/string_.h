//
// Created by averk on 26.02.2022.
//
#ifndef UNTITLED8_STRING__H
#define UNTITLED8_STRING__H

#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#define ASSERT_STRING(expected, got) assertString ( expected , got , \
__FILE__ , __FUNCTION__ , __LINE__ )

#define  MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag ;

BagOfWords _bag2 ;

// возвращает количество символов в строке, начиная с адреса begin
size_t strlen_(const char *begin);

// возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end не включая end. Если символ не найден, возвращается значение end
char *find(char *begin, char *end, int ch);

// возвращает указатель на первый символ, отличный от пробельных, расположенный на ленте памяти,
// начиная с begin и заканчивая ноль-символом. Если символ не найден, возвращается адрес первого ноль-символа
char *findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin
// или на первый ноль-символ
char *findSpace(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend.
// Если символ не найден, возвращается адрес rend
char *findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
// начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend
char *findSpaceReverse(char *rbegin, const char *rend);


// возвращает отрицательное значение, если lhs располагается до rhs в лексикографическом порядке,
// значение 0, если lhs и rhs равны, иначе – положительное значение
int strcmp(const char *lhs, const char *rhs);

// возвращает указатель на следующий свободный фрагмент памяти в destination.
// Записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

// возвращает указатель на следующий свободный фрагмент памяти в destination.
// Записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource,
// удовлетворяющие функции-предикату f
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// возвращает указатель на первый свободный фрагмент памяти в destination.
// Записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
// заканчивая rendSource, удовлетворяющие функции-предикату f.
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

// возвращает указатель на конец строки s
char *getEndOfString(char *s);

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);


// возвращает 1, если было найдено слово word, начиная с begin и заканчивая ноль-символом
// иначе возвращает 0
int getWord(char *beginSearch, WordDescriptor *word);

// возвращает значение 'истина', если было найдено слово word, начиная с rbegin и заканчивая rend
// иначе возвращает 0
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

// возвращает отрицательное значение, если w1 располагается до w2 в лексикографическом порядке,
// значение 0, если w1 и w2 равны, иначе – положительное значение
int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

// записывает в массив слов bag позиции начала и конца каждого слова  в строке s
void getBagOfWords(BagOfWords *bag, char *s);


#endif //UNTITLED8_STRING__H
