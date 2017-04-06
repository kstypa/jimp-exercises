//
// Created by karol on 4/6/17.
//

#include "TextPool.h"

using ::std::string;
using ::std::experimental::string_view;

namespace pool {

    TextPool::TextPool() {

    }

    TextPool::TextPool(TextPool &&pool) {
        Move(std::move(pool));
    }

    void TextPool::Move(TextPool &&pool) {
        strings_;
        swap(strings_, pool.strings_);
    }

    TextPool &TextPool::operator=(TextPool &&pool) {
        if (this == &pool) {
            return pool;
        }
        Move(std::move(pool));
    }

    TextPool::~TextPool() {

    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        auto item = strings_.insert(str);
        return *item.first;
    }

    size_t TextPool::StoredStringCount() const {
        return strings_.size();
    }
}