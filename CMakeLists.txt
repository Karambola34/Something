cmake_minimum_required(VERSION 3.20)
project(untitled8 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled8 main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h libs/algorithms/algorithm.c libs/algorithms/algorithm.h libs/algorithms/array/array.c libs/algorithms/array/array.h libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h libs/string/string_.c libs/string/string_.h libs/string/tasks/removeNonLetters.h libs/string/tasks/removeExtraSpaces.h libs/string/tasks/digitToStartTransform.h libs/string/tasks/replaceDigitsBySpaces.h libs/string/tasks/areWordsOrdered.h libs/string/tasks/outputReversedString.h libs/string/tasks/amountOfPalindromes.h libs/string/tasks/getMixedString.h libs/string/tasks/getStringWithReversedWords.h "libs/string/tasks/printWordBeforeFirstWordWithA.h" libs/string/tasks/lastWordInFirstStringInSecondString.h libs/string/tasks/hasEqualWords.h libs/string/tasks/replace.h)

