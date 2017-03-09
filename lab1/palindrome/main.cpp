//
// Created by karol on 3/8/17.
//

#include "Palindrome.h"

int main(){
    char menu;
    std::string str;
    std::cout << "--- PALINDROM ---\n";
    while (true){
        std::cout << "c - sprawdz palindrom\tx - wyjscie\n";
        std::cin >> menu;
        if (menu == 'c') {
            std::cout << "Podaj ciag znakow do sprawdzenia\n";
            std::cin >> str;
            if (is_palindrome(str))
                std::cout << "\"" << str << "\" jest palindromem\n";
            else
                std::cout << "\"" << str << "\" nie jest palindromem\n";
            break;
        }
        else if (menu == 'x')
            break;
        else
            std::cout << "Nie podano poprawnej opcji\n";
    }

    return 0;
}