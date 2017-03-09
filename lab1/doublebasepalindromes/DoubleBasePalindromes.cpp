//
// Created by karol on 3/8/17.
//

#include "DoubleBasePalindromes.h"
#include "Palindrome.h"

std::string dec2bin(int dec){
    if (dec == 0)
        return "0";
    std::string bin;
    while (dec > 0){
        bin = std::to_string(dec % 2) + bin;
        dec /= 2;
    }
    return bin;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    std::string decstr, bin;
    std::vector<int> palindromes;
    uint64_t sum = 0;
    for (int i = 0; i < max_vaule_exculsive; i++){
        decstr = std::to_string(i);
        if (is_palindrome(decstr)){
            bin = dec2bin(i);
            if (is_palindrome(bin))
                palindromes.push_back(i);
        }
    }
    for (int n : palindromes)
        sum += n;
    return sum;
}