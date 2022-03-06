//
// Created by averk on 07.03.2022.
//

#ifndef UNTITLED8_AMOUNTOFPALINDROMES_H
#define UNTITLED8_AMOUNTOFPALINDROMES_H

#include  "../string_.h"
#include <assert.h>


// возвращает значение 'истина', если слово  является палиндромом, начиная с begin и заканчивая end
// иначе возвращает значение 'ложь'
int isPalindrome(char *begin,char *end);

// возвращает число слов - палиндромов в строке s
int amountOfPalindromes(char *s);

void test_amountOfPalindromes();

#endif //UNTITLED8_AMOUNTOFPALINDROMES_H
