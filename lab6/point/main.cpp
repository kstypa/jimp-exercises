//
// Created by karol on 4/6/17.
//

#include <iostream>
#include <sstream>
#include "Point.h"

int main() {
    Point p;
    std::cin >> p;
    std::cout << p << std::endl;
    std::stringstream ss;
    ss << p;
    std::cout << ss.str() << std::endl;

    return 0;
}