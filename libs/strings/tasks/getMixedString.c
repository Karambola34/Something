//
// Created by averk on 07.03.2022.
//

#include "getMixedString.h"

void getMixedString(char *s, char *s1, char *s2) {
    char *begin = s;
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            begin = copy(word1.begin, word1.end, begin);
            *begin = ' ';
            begin++;
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            begin = copy(word2.begin, word2.end, begin);
            *begin = ' ';
            begin++;
            beginSearch2 = word2.end;
        }

    }

    begin--;
    *begin = '\0';
}

void test_s1IsLonger() {
    char s[MAX_STRING_SIZE];
    char s1[] = "In a restless search for new opportunities and new ways of living";
    char s2[] = "The mystery and the promise of distant horizons";
    getMixedString(s, s1, s2);
    ASSERT_STRING(
            "In The a mystery restless and search the for promise new of opportunities distant and horizons new ways of living",
            s);
}

void test_s2IsLonger() {
    char s[MAX_STRING_SIZE];
    char s1[] = "\tone three \tfive";
    char s2[] = "two four six seven eight nine";
    getMixedString(s, s1, s2);
    ASSERT_STRING("one two three four five six seven eight nine", s);
}

void test_bothEqual() {
    char s[MAX_STRING_SIZE];
    char s1[] = "one three five";
    char s2[] = "two four six ";
    getMixedString(s, s1, s2);
    ASSERT_STRING("one two three four five six", s);
}

void test_s1Empty() {
    char s[MAX_STRING_SIZE];
    char s1[] = "";
    char s2[] = "two four six seven eight nine";
    getMixedString(s, s1, s2);
    ASSERT_STRING("two four six seven eight nine", s);
}

void test_s2Empty() {
    char s[MAX_STRING_SIZE];
    char s1[] = "fish catfish fishNchips      ";
    char s2[] = "";
    getMixedString(s, s1, s2);
    ASSERT_STRING("fish catfish fishNchips", s);
}

void test_bothEmpty() {
    char s[MAX_STRING_SIZE];
    char s1[] = "";
    char s2[] = "";
    getMixedString(s, s1, s2);
    ASSERT_STRING("", s);
}

void test_getMixedString() {
    test_s1IsLonger();
    test_s2IsLonger();
    test_bothEqual();
    test_s1Empty();
    test_s2Empty();
    test_s2Empty();
}