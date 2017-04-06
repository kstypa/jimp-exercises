//
// Created by karol on 4/6/17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool {
    class TextPool {
    public:
        TextPool();
        TextPool(const std::initializer_list<std::string> &elements) : strings_(elements) {}

        TextPool(const TextPool &pool) = delete;
        TextPool(TextPool &&pool);
        TextPool &operator=(const TextPool &pool) = delete;
        TextPool &operator=(TextPool &&pool);
        ~TextPool();

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:
        std::set<std::string> strings_;

        void Move(TextPool &&pool);
    };
}



#endif //JIMP_EXERCISES_TEXTPOOL_H
