//
// Created by karol on 4/20/17.
//

#include "ArrayFill.h"


namespace arrays {
    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

   IncrementalFill::IncrementalFill(std::initializer_list<int> elements) : start_(*elements.begin()), step_(1) {
       if(elements.size() == 2)
           step_ = *std::rbegin(elements);
   }

    int IncrementalFill::Value(int index) const {
        return start_ + index * step_;
    }

    RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> generator, std::unique_ptr<std::uniform_int_distribution<int>> distribution) : generator_(move(generator)), distribution_(move(distribution)) {

    }

    int RandomFill::Value(int index) const {
        auto &dist = *distribution_;
        auto &gen = *generator_;
        return dist(gen);
    }

    SquaredFill::SquaredFill() : a_(1), b_(0) {}

    SquaredFill::SquaredFill(std::initializer_list<int> elements) : a_(*elements.begin()), b_(0) {
        if(elements.size() == 2)
            b_ = *std::rbegin(elements);
    }

    int SquaredFill::Value(int index) const {
        return a_ * index * index + b_;
    }


}
