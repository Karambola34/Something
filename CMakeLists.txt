cmake_minimum_required(VERSION 3.20)
project(untitled8 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled8 main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h libs/algorithms/algorithm.c libs/algorithms/algorithm.h libs/algorithms/array/array.c libs/algorithms/array/array.h libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h libs/strings/string_.c libs/strings/string_.h libs/strings/tasks/removeNonLetters.h libs/strings/tasks/removeExtraSpaces.h libs/strings/tasks/digitToStartTransform.h libs/strings/tasks/replaceDigitsBySpaces.h libs/strings/tasks/areWordsOrdered.h libs/strings/tasks/outputReversedString.h libs/strings/tasks/amountOfPalindromes.h libs/strings/tasks/getMixedString.h libs/strings/tasks/getStringWithReversedWords.h "libs/strings/tasks/printWordBeforeFirstWordWithA.h" libs/strings/tasks/lastWordInFirstStringInSecondString.h libs/strings/tasks/hasEqualWords.h libs/strings/tasks/replace.h)

