
project(palindrome)

set(HEDEAR_FILES Palindrome.h ReverseString.h)
set(SOURCE_FILES Palindrome.cpp ReverseString.cpp)

add_library(libpalindrome STATIC ${SOURCE_FILES})
target_include_directories(libpalindrome PUBLIC .)

add_executable(palindrome ${SOURCE_FILES} main.cpp)

target_link_libraries(palindrome libpalindrome)

