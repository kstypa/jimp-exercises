//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include "ArabicRoman.h"
#include "../lib/memleak/MemLeakTest.h"

using ::arabicroman::ArabicToRoman;

class ArabicRomanTest : public ::testing::Test, MemLeakTest {
public:
};

TEST_F(ArabicRomanTest, CannotConvertArabicLesserThan1) {
    int arabic = 0;
    std::string roman = "";
    EXPECT_EQ(roman, ArabicToRoman(arabic));
}

TEST_F(ArabicRomanTest, CannotConvertArabicGreaterThan3999) {
    int arabic = 4000;
    std::string roman = "";
    EXPECT_EQ(roman, ArabicToRoman(arabic));
}

TEST_F(ArabicRomanTest, CanConvertSingleArabicToRoman1) {
    int arabic = 1;
    std::string roman = "I";
    EXPECT_EQ(roman, ArabicToRoman(arabic));
}

TEST_F(ArabicRomanTest, CanConvertSingleArabicToRoman8) {
    int arabic = 8;
    std::string roman = "VIII";
    EXPECT_EQ(roman, ArabicToRoman(arabic));
}

TEST_F(ArabicRomanTest, CanConvertArabicToRoman2137) {
    int arabic = 2137;
    std::string roman = "MMCXXXVII";
    EXPECT_EQ(roman, ArabicToRoman(arabic));
}

TEST_F(ArabicRomanTest, CanConvertArabicToRoman1488) {
    int arabic = 1488;
    std::string roman = "MCDLXXXVIII";
    EXPECT_EQ(roman, ArabicToRoman(arabic));
}