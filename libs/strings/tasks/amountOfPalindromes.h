//
// Created by averk on 07.03.2022.
//

#ifndef UNTITLED8_AMOUNTOFPALINDROMES_H
#define UNTITLED8_AMOUNTOFPALINDROMES_H

#include  "../string_.h"



// возвращает значение 'истина', если слово  является палиндромом, начиная с begin и заканчивая end
// иначе возвращает значение 'ложь'
int isPalindrome(char *begin, char *end) {
    end--;
    while (end - begin > 0) {
        if (*begin != *end)
            return 0;
        begin++;
        end--;
    }
    return 1;
}

// возвращает число слов - палиндромов в строке s
int amountOfPalindromes(char *s) {
    int amountOfPalindromes = 0;
    char *begin = findNonSpace(s);
    char *end = getEndOfString(s);
    char *commaPosition = find(begin, end, ',');
    while (*commaPosition != *end) {
        begin = findNonSpace(begin);
        amountOfPalindromes += isPalindrome(begin, commaPosition );
        begin = commaPosition + 1;
        commaPosition = find(begin, end, ',');
        if (*commaPosition == *end) {
            begin = findNonSpace(begin);
            amountOfPalindromes += isPalindrome(begin, findSpace(begin));
        }

    }

    return amountOfPalindromes;
}


void test_arePalindromes() {
    char s[] = "fool,noon, pool, cool, \tnun,toot,121 \t \t";
    assert(amountOfPalindromes(s) == 4);
}

void test_noPalindromes() {
    char s[] = "fool, pool, cool \t \t";
    assert(amountOfPalindromes(s) == 0);
}

void test_empty() {
    char s[] = "";
    assert(amountOfPalindromes(s) == 0);
}

void test_amountOfPalindromes() {
    test_arePalindromes();
    test_noPalindromes();
    test_empty();
}

#endif //UNTITLED8_AMOUNTOFPALINDROMES_H
