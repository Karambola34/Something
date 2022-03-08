//
// Created by averk on 08.03.2022.
//

#include "lastWordInFirstStringInSecondString.h"


WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    WordDescriptor word = {" ", " "};
    bool isFoundLast = false;
    for (int i = _bag.size - 1; i >= 0; i--)
        for (int j = _bag2.size - 1; j >= 0; j--)
            if (areWordsEqual(_bag.words[i], _bag2.words[j]) == 0) {
                word = _bag.words[i];
                return word;
            }
    return word;
}


void wordDescriptorToString(WordDescriptor word, char *destination) {
    *copy(word.begin, word.end, destination) = '\0';

}

void test_isLastWordInFirstStringInSecondString() {
    char s1[] = " one two three four five";
    char s2[] = "one three six seven";
    WordDescriptor word =
            lastWordInFirstStringInSecondString(s1, s2);
    char s[MAX_STRING_SIZE];
    wordDescriptorToString(word, s);
    ASSERT_STRING ("three", s);
}

void test_notWordInFirstStringInSecondString() {
    char s1[] = "the caterpillar turns into a butterfly";
    char s2[] = "hen lays eggs";
    WordDescriptor word =
            lastWordInFirstStringInSecondString(s1, s2);
    char s[MAX_STRING_SIZE];
    wordDescriptorToString(word, s);
    ASSERT_STRING ("", s);
}

void test_emptyWords() {
    char s1[] = "";
    char s2[] = "";
    WordDescriptor word =
            lastWordInFirstStringInSecondString(s1, s2);
    char s[MAX_STRING_SIZE];
    wordDescriptorToString(word, s);
    ASSERT_STRING ("", s);
}

void test_lastWordInFirstStringInSecondString() {
    test_isLastWordInFirstStringInSecondString();
    test_notWordInFirstStringInSecondString();
    test_emptyWords();
}