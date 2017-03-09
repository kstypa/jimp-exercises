
project(doublebasepalindromes)

set(HEDEAR_FILES DoubleBasePalindromes.h Palindrome.h ReverseString.h)
set(SOURCE_FILES DoubleBasePalindromes.cpp Palindrome.cpp ReverseString.cpp)

add_library(libdoublebasepalindromes STATIC ${SOURCE_FILES})
target_include_directories(libdoublebasepalindromes PUBLIC .)

add_executable(doublebasepalindromes ${SOURCE_FILES} main.cpp)

target_link_libraries(doublebasepalindromes libdoublebasepalindromes)

