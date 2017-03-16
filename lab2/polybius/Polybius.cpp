//
// Created by karol on 3/16/17.
//

#include "Polybius.h"
using std::string;

std::string PolybiusCrypt(std::string message){
    string encrypted = "";

    message.erase(std::remove_if(message.begin(), message.end(), isspace), message.end());
    std::transform(message.begin(), message.end(), message.begin(), toupper);
    std::replace(message.begin(), message.end(), 'J', 'I');

    std::map<char, string> polybiusCoords = {
            {'A', "11"},
            {'B', "12"},
            {'C', "13"},
            {'D', "14"},
            {'E', "15"},
            {'F', "21"},
            {'G', "22"},
            {'H', "23"},
            {'I', "24"},
            {'K', "25"},
            {'L', "31"},
            {'M', "32"},
            {'N', "33"},
            {'O', "34"},
            {'P', "35"},
            {'Q', "41"},
            {'R', "42"},
            {'S', "43"},
            {'T', "44"},
            {'U', "45"},
            {'V', "51"},
            {'W', "52"},
            {'X', "53"},
            {'Y', "54"},
            {'Z', "55"},
    };

    for(const auto n : message){
        encrypted += polybiusCoords[n];
    }

    return encrypted;
}

std::string PolybiusDecrypt(std::string crypted){
    string decrypted = "";
    const string polybiusSquare[5][5] = {
            {"A", "B", "C", "D", "E"},
            {"F", "G", "H", "I", "K"},
            {"L", "M", "N", "O", "P"},
            {"Q", "R", "S", "T", "U"},
            {"V", "W", "X", "Y", "Z"},
    };

    for(int i = 0; i < crypted.size(); i+=2){
        int row = std::stoi(crypted.substr(i,1)) - 1;
        int col = std::stoi(crypted.substr(i+1,1)) - 1;
        decrypted += polybiusSquare[row][col];
    }

    std::transform(decrypted.begin(), decrypted.end(), decrypted.begin(), tolower);

    return decrypted;
}