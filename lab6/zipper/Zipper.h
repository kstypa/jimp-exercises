//
// Created by karol on 4/6/17.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include <vector>
#include <string>

namespace datastructures {
    class Iterator {
    public:

    private:
        bool operator!=(Iterator);
        Iterator &operator++();
        std::pair<std::string, int> operator*();
    };

    class Zipper {
    public:

        static std::pair zip(std::vector<std::string>, std::vector<int>);
    private:

    };
}


#endif //JIMP_EXERCISES_ZIPPER_H
