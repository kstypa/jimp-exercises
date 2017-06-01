//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include "ArabicRoman.h"
#include "../lib/memleak/MemLeakTest.h"

using ::arabicroman::RomanToArabic;

class ArabicRomanTest : public ::testing::Test, MemLeakTest {
public:
};

TEST_F(ArabicRomanTest, CannotConvertArabicLesserThan1) {
    std::string roman = "";
    int arabic = 0;
    EXPECT_EQ(arabic, RomanToArabic(roman));
}

TEST_F(ArabicRomanTest, CanConvertSingleRomanToArabic) {
    std::string roman = "L";
    int arabic = 50;
    EXPECT_EQ(arabic, RomanToArabic(roman));
}

TEST_F(ArabicRomanTest, CanConvertRomanToArabic68) {
    std::string roman = "LXVIII";
    int arabic = 68;
    EXPECT_EQ(arabic, RomanToArabic(roman));
}

TEST_F(ArabicRomanTest, CanConvertRomanToArabic69) {
    std::string roman = "LXIX";
    int arabic = 69;
    EXPECT_EQ(arabic, RomanToArabic(roman));
}

TEST_F(ArabicRomanTest, CanConvertRomanToArabic1488) {
    std::string roman = "MCDLXXXVIII";
    int arabic = 1488;
    EXPECT_EQ(arabic, RomanToArabic(roman));
}

TEST_F(ArabicRomanTest, CanConvertRomanToArabic2137) {
    std::string roman = "MMCXXXVII";
    int arabic = 2137;
    EXPECT_EQ(arabic, RomanToArabic(roman));
}

TEST_F(ArabicRomanTest, CanConvertRomanToArabic3999) {
    std::string roman = "MMMCMXCIX";
    int arabic = 3999;
    EXPECT_EQ(arabic, RomanToArabic(roman));
}