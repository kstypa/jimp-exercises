//
// Created by karol on 5/18/17.
//

#include "FactoryMethod.h"
#include <iostream>
#include <complex>
#include <memory>
#include <vector>

using namespace factoryMethod;

int main() {
//    std::cout << Sum(std::complex<double>{1,2}, std::complex<double>{3,4}) << std::endl;
//    double x = 5.1;

//    int *ptr1 = new int{5};
//    auto ptr2 = std::make_shared<int>(6);
    std::vector<std::complex<double>> v {std::complex<double>{1,2}, std::complex<double>{3,4}, std::complex<double>{3,4}};
    std::vector<int> v2 {2,4,4};
//    std::cout << Value(v.begin()) << std::endl;
    std::cout << Mean<std::complex<double>>(v) << std::endl << Mean<double>(v2) << std::endl;

//    delete(ptr1);
    return 0;
}