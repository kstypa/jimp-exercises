//
// Created by karol on 4/27/17.
//

#include <iostream>
#include "Ksztalt.h"

Trojkat::Trojkat() : h_(0) {

}

Trojkat::Trojkat(double h) {
    h_ = h;
}

Trojkat::~Trojkat() {

}

void Trojkat::rysuj() {
    for(int i = 0; i < h_; i++) {
        for(int j = 0; j <= i; j++)
            std::cout << "# ";
        std::cout << std::endl;
    }
}

Kwadrat::Kwadrat() : a_(0) {

}

Kwadrat::Kwadrat(double a) {
    a_ = a;
}

Kwadrat::~Kwadrat() {

}

void Kwadrat::rysuj() {
    for(int i = 0; i < a_; i++) {
        for(int j = 0; j < a_; j++)
            std::cout << "# ";
        std::cout << std::endl;
    }
}

Kolo::Kolo() {

}

Kolo::~Kolo() {

}

void Kolo::rysuj() {
    std::cout << "    # # #     \n"
            "  # # # # #   \n"
            "# # # # # # # \n"
            "# # # # # # # \n"
            "# # # # # # # \n"
            "  # # # # #   \n"
            "    # # #     \n";
}

