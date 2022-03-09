
#include "libs/strings/tasks/removeNonLetters.h"
#include "libs/strings/tasks/removeExtraSpaces.h"
#include "libs/strings/tasks/digitToStartTransform.h"
#include "libs/strings/tasks/replaceDigitsBySpaces.h"
#include "libs/strings/tasks/areWordsOrdered.h"
#include "libs/strings/tasks/outputReversedString.h"
#include "libs/strings/tasks/amountOfPalindromes.h"
#include "libs/strings/tasks/getMixedString.h"
#include "libs/strings/tasks/getStringWithReversedWords.h"
#include "libs/strings/tasks/printWordBeforeFirstWordWithA.h"
#include "libs/strings/tasks/lastWordInFirstStringInSecondString.h"
#include  "libs/strings/tasks/hasEqualWords.h"
#include  "libs/strings/tasks/replace.h"


static void test_strlen_() {
    char s[] = "    coconut orange and cheese";
    assert(strlen_(s) == 29);
}

static void test_findNonSpace() {
    char s[] = "\t  cake   pancake";
    char *res = findNonSpace(s);
    assert(*res == 'c');
    assert(res == &s[3]);
}

static void test_findSpace() {
    char s[] = "oneoneone\t    oneoneone";
    char *res = findSpace(s);
    assert(res == &s[9]);
}

static void test_findNonSpaceReverse() {
    char s[] = "cookie   ";
    char *res = findNonSpaceReverse(&s[8], &s[-1]);
    assert(*res == 'e');
    assert(res == &s[5]);
}

static void test_findSpaceReverse() {
    char s[] = "lets count letters";
    char *res = findSpaceReverse(&s[17], &s[-1]);
    assert(res == &s[10]);
}

static void test_EqualStrcmp() {
    char s1[] = "picnic";
    char s2[] = "picnic";
    assert(strcmp(s1, s2) == 0);
}

static void test_firstBiggerStrcmp() {
    char s1[] = "alphabet";
    char s2[] = "barricade";
    assert(strcmp(s1, s2) == -1);
}

static void test_secondBiggerStrcmp() {
    char s1[] = "blaster";
    char s2[] = "able";
    assert(strcmp(s1, s2) == 1);
}


static void test_copy() {
    char s1[] = "1234567";
    char s2[] = "";
    char *begin = s2;
    copy(s1, &s1[7], s2);
    char *end = begin + strlen_(s1);
    *end = '\0';
    ASSERT_STRING("1234567", s2);
}

static void test_copyIf() {
    char s1[] = "123gh45 6";
    char s2[6];
    char *begin = s2;
    copyIf(s1, &s1[9], s2, isdigit);
    char *end = begin + 6;
    *end = '\0';
    ASSERT_STRING("123456", s2);
}

static void test_copyIfReverse() {
    char s1[] = "1 2 3 4 fdfdfd56";
    char s2[] = "";
    copyIfReverse(&s1[16], s1, s2, isdigit);
    ASSERT_STRING("654321", s2);
}

static void test_getEndOfString() {
    char s[6] = "12345";
    char *res = findNonSpace(s);
    assert(res == &s[6]);
}

void test_string_() {
    test_strlen_();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_EqualStrcmp();
    test_firstBiggerStrcmp();
    test_secondBiggerStrcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
    test_getEndOfString();
}


int main() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitToStartLettersFirstDigitsSecond();
    test_replaceDigitsBySpaces();
    test_areWordsOrdered();
    pseudoTestOutputReversedString();
    test_amountOfPalindromes();
    test_getMixedString();
    test_getStringWithReversedWords();
    testAll_getWordBeforeFirstWordWithA();
    test_lastWordInFirstStringInSecondString();
    test_hasEqualWords();
    test_replace();
    test_string_();


    return 0;
}