//
// Created by averk on 09.03.2022.
//

#ifndef UNTITLED8_HASPAIROFWORDSWITHEQUALLETTERSET_H
#define UNTITLED8_HASPAIROFWORDSWITHEQUALLETTERSET_H

#include  "../string_.h"

// возвращает значение 'истина', если в строке s есть одинаковые слова,
// иначе возвращает значение 'ложь'
int hasEqualWords(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = 0; i < _bag.size; i++)
        for (int j = i + 1; j < _bag.size; j++)
            if (areWordsEqual(_bag.words[i], _bag.words[j]) == 0)
                return 1;
    return 0;
}

void test_hasEqualWords() {
    char s1[] = "can cat can cannon";
    assert(hasEqualWords(s1));
    char s2[] = "can cannon cannot";
    assert(!hasEqualWords(s2));
    char s3[] = "";
    assert(!hasEqualWords(s3));

}

#endif //UNTITLED8_HASPAIROFWORDSWITHEQUALLETTERSET_H
