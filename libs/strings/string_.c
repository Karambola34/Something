//
// Created by averk on 26.02.2022.
//

#include "string_.h"


size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin) && (*begin != '\0'))
        begin++;
    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && (*begin != '\0'))
        begin++;
    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;
    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;
    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;

    }
    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);
    return endSource - beginSource + beginDestination;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource))
            *beginDestination++ = *beginSource;

        beginSource++;
    }


    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource)
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
            rbeginSource--;
        }
    return beginDestination;
}

char *getEndOfString(char *begin) {
    while (*begin != '\0')
        begin++;
    return begin;
}

void assertString(const char *expected, char *got, char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}


int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend) + 1;
    if (word->end == rend)
        return false;
    word->begin = findSpaceReverse(word->end, rend) + 1;

    return true;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    char *beginWord1 = w1.begin;
    char *beginWord2 = w2.begin;
    while (*beginWord1 == *beginWord2 && beginWord1 != w1.end) {
        beginWord1++;
        beginWord2++;
    }
    return *beginWord1 - *beginWord2;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    char *begin = s;
    size_t size = 0;
    WordDescriptor word;
    while (getWord(begin, &word)) {
        bag->words[size] = word;

        size++;
        begin = word.end;
    }
    bag->size = size;
}






