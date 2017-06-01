//
// Created by karol on 6/1/17.
//

#include "ArabicRoman.h"

namespace arabicroman {

    std::string ArabicToRoman(int arabic) {
        if(arabic <= 0 || arabic >= 4000)
            return "";
        std::string result;

        int thousands = arabic / 1000;
        for(int i = 0; i < thousands; i++)
            result += "M";

        arabic -= thousands * 1000;
        int hundreds = arabic / 100;
        switch(hundreds) {
            case 1: result += "C"; break;
            case 2: result += "CC"; break;
            case 3: result += "CCC"; break;
            case 4: result += "CD"; break;
            case 5: result += "D"; break;
            case 6: result += "DC"; break;
            case 7: result += "DCC"; break;
            case 8: result += "DCCC"; break;
            case 9: result += "CM"; break;
            default: break;
        }

        arabic -= hundreds * 100;
        int tens = arabic / 10;
        switch(tens) {
            case 1: result += "X"; break;
            case 2: result += "XX"; break;
            case 3: result += "XXX"; break;
            case 4: result += "XL"; break;
            case 5: result += "L"; break;
            case 6: result += "LX"; break;
            case 7: result += "LXX"; break;
            case 8: result += "LXXX"; break;
            case 9: result += "XC"; break;
            default: break;
        }

        arabic -= tens * 10;
        switch(arabic) {
            case 1: result += "I"; break;
            case 2: result += "II"; break;
            case 3: result += "III"; break;
            case 4: result += "IV"; break;
            case 5: result += "V"; break;
            case 6: result += "VI"; break;
            case 7: result += "VII"; break;
            case 8: result += "VIII"; break;
            case 9: result += "IX"; break;
            default: break;
        }

        return result;
    }

    int RomanToArabic(const std::string &roman) {
        int result = 0;
        if(roman == "")
            return result;
        for(int j = 0; j < roman.size(); ++j) {
            if(roman[j] == 'M') result += 1000;
            else if (roman[j] == 'C') {
                if(j+1 != roman.size() && roman[j+1] == 'M') {
                    result += 900;
                    ++j;
                }
                else if(j+1 != roman.size() && roman[j+1] == 'D') {
                    result += 400;
                    ++j;
                }
                else result += 100;
            }
            else if (roman[j] == 'D') result += 500;
            else if (roman[j] == 'X') {
                if(j+1 != roman.size() && roman[j+1] == 'C') {
                    result += 90;
                    ++j;
                }
                else if(j+1 != roman.size() && roman[j+1] == 'L') {
                    result += 40;
                    ++j;
                }
                else result += 10;
            }
            else if (roman[j] == 'L') result += 50;
            else if (roman[j] == 'I') {
                if(j+1 != roman.size() && roman[j+1] == 'X') {
                    result += 9;
                    ++j;
                }
                else if(j+1 != roman.size() && roman[j+1] == 'V') {
                    result += 4;
                    ++j;
                }
                else result += 1;
            }
            else if (roman[j] == 'V') result += 5;
        }

        return result;
    }
}