//
// Created by averk on 06.03.2022.
//

#include "outputReversedString.h"

void outputReversedString(char *s) {
    copy(s, getEndOfString(s),_stringBuffer);
    getBagOfWords(&_bag, _stringBuffer);
    for (int i = _bag.size - 1; i >= 0; i--) {
        *_bag.words[i].end='\0';
        printf("%s ",_bag.words[i].begin);
    }
}

void pseudoTestOutputReversedString1(){
    char s[]="";
    printf("source string: \n%s\noutput string:\n",s);
    outputReversedString(s);
    printf("\n");
}

void pseudoTestOutputReversedString2(){
    char s[]="zero one tulip\t candycorne";
    printf("source string: \n%s\noutput string:\n",s);
    outputReversedString(s);
    printf("\n");
}



void pseudoTestOutputReversedString(){
    pseudoTestOutputReversedString1();
    pseudoTestOutputReversedString2();
}
