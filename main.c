
#include "libs/strings/tasks/removeNonLetters.h"
#include "libs/strings/tasks/removeExtraSpaces.h"
#include "libs/strings/tasks/digitToStartTransform.h"
#include "libs/strings/tasks/replaceDigitsBySpaces.h"
#include "libs/strings/tasks/areWordsOrdered.h"
#include "libs/strings/tasks/outputReversedString.h"
#include "libs/strings/tasks/amountOfPalindromes.h"
#include "libs/strings/tasks/getMixedString.h"
#include "libs/strings/tasks/getStringWithReversedWords.h"




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
    return 0;
}