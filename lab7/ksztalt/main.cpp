//
// Created by karol on 4/27/17.
//

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "Ksztalt.h"

int main() {
//    Trojkat trojkat(5);
//    trojkat.rysuj();
//
//    std::cout << std::endl;
//
//    Kwadrat kwadrat(5);
//    kwadrat.rysuj();

    std::srand(time(0));
    std::vector<Ksztalt *> ksztalty;
    for(int i = 0; i < 10; i++) {
        int r = rand()%100;
        if(r < 33) {
            ksztalty.push_back(new Trojkat(5));
        }
        else if(r >= 33 && r < 67) {
            ksztalty.push_back(new Kwadrat(5));
        }
        else {
            ksztalty.push_back(new Kolo(5));
        }
    }

    for(auto n : ksztalty) {
        n->rysuj();
        std::cout << std::endl;
        delete n;
    }

    return 0;
}