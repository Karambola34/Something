//
// Created by averk on 01.03.2022.
//

#ifndef UNTITLED8_DIGITTOSTARTTRANSFORM_H
#define UNTITLED8_DIGITTOSTARTTRANSFORM_H

#include  "../string_.h"

// преобразовывает строку таким образом, чтобы цифры каждого слова word были перенесены в конец слова,
// а буквы – в начало слова, без изменения порядка следования
void digitToStartLettersFirstDigitsSecond(WordDescriptor word);


// считывает все слова в строке sgi
void digitToStartForAllWords(char *s);

void test_digitToStartLettersFirstDigitsSecond();



#endif //UNTITLED8_DIGITTOSTARTTRANSFORM_H
