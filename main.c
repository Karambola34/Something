
#include "libs/strings/tasks/removeNonLetters.h"
#include "libs/strings/tasks/removeExtraSpaces.h"
#include "libs/strings/tasks/digitToStartTransform.h"
#include "libs/strings/tasks/replaceDigitsBySpaces.h"
#include "libs/strings/tasks/areWordsOrdered.h"
#include "libs/strings/tasks/outputReversedString.h"


int main() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitToStartLettersFirstDigitsSecond();
    test_replaceDigitsBySpaces();
    test_areWordsOrdered();
    pseudoTestOutputReversedString();
    return 0;
}