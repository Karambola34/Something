//
// Created by averk on 09.03.2022.
//

#ifndef UNTITLED8_REPLACE_H
#define UNTITLED8_REPLACE_H

#include  "../string_.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }
    WordDescriptor searchingWord;
    while (*readPtr != '\0') {
        if (*readPtr == *word1.begin) {
            getWord(readPtr, &searchingWord);
            if (getWord(readPtr, &searchingWord)&& areWordsEqual(word1, searchingWord) <= 0) {
                copy(word2.begin, word2.end, recPtr);
                recPtr += w2Size;
                readPtr += w1Size;
            }
        }
        *recPtr = *readPtr;
        recPtr++;
        readPtr++;
    }
    *recPtr = '\0';
}

void test_replace(){
    char s[]="zero zero one one two three one";
    char s1[]="zero";
    char s2[]="one";

    replace(s,s1,s2);
    ASSERT_STRING("one one one one two three one",s);
}
#endif //UNTITLED8_REPLACE_H
