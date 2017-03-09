//
// Created by karol on 3/8/17.
//

#include "Palindrome.h"

bool is_palindrome(std::string str){
    std::string rev = reverse(str);
    if (rev == str)
        return true;
    else
        return false;
}