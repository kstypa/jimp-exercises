//
// Created by karol on 5/18/17.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <algorithm>

namespace factoryMethod {

    template<class T>
    T Create();

    template<class T>
    T Create() {
        return T();
    }

    template<class T>
    T Sum(const T &a, const T &b) {
        return a + b;
    }

    template<class T>
    auto Value(T ptr) {
        return *ptr;
    }

    template<class R, class V>
    R Mean(const V &v) {
        return std::accumulate(std::begin(v), std::end(v), R()) / R(v.size());
    }

    class MyType {
    public:
        MyType();
        std::string SayHello();
    };

}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
