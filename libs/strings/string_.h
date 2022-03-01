//
// Created by averk on 26.02.2022.
//
#ifndef UNTITLED8_STRING__H
#define UNTITLED8_STRING__H

#define ASSERT_STRING( expected , got ) assertString ( expected , got , \
__FILE__ , __FUNCTION__ , __LINE__ )

#include <stdio.h>
#include <memory.h>
#include <ctype.h>


// возвращает количество символов в строке, начиная с адреса begin
size_t strlen_ (const char *begin);

// возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end не включая end. Если символ не найден, возвращается значение end
char* find(char *begin, char *end, int ch);

// возвращает указатель на первый символ, отличный от пробельных, расположенный на ленте памяти,
// начиная с begin и заканчивая ноль-символом. Если символ не найден, возвращается адрес первого ноль-символа
char* findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin
// или на первый ноль-символ
char* findSpace(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend.
// Если символ не найден, возвращается адрес rend
char* findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
// начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend
char* findSpaceReverse(char *rbegin, const char *rend);


// возвращает отрицательное значение, если lhs располагается до rhs в лексикографическом порядке,
// значение 0, если lhs и rhs равны, иначе – положительное значение
int strcmp ( const char * lhs , const char * rhs );

// возвращает указатель на следующий свободный фрагмент памяти в destination.
// Записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource
char* copy(const char *beginSource, const char *endSource,char *beginDestination);

// возвращает указатель на следующий свободный фрагмент памяти в destination.
// Записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource,
// удовлетворяющие функции-предикату f
char* copyIf(char *beginSource, const char *endSource,char *beginDestination, int (*f)(int));

// возвращает указатель на первый свободный фрагмент памяти в destination.
// Записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
// заканчивая rendSource, удовлетворяющие функции-предикату f.
char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char *getEndOfString (char *s);

void assertString ( const char * expected , char * got ,
                    char const * fileName , char const * funcName ,
                    int line );


#endif //UNTITLED8_STRING__H
