//
// Created by karol on 3/8/17.
//

#include "ReverseString.h"

std::string reverse(std::string str) {
    size_t len = str.size();
    if (str.size() <= 1)
        return str;
    return reverse(str.substr(1,len-1)) + str[0];
}
