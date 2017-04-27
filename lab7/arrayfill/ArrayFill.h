//
// Created by karol on 4/20/17.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>
#include <cstdio>
#include <random>
#include <memory>

namespace arrays {
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(std::initializer_list<int> elements);
        virtual int Value(int index) const override;
    private:
        int start_;
        int step_;
    };

    class RandomFill : public ArrayFill {
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> generator, std::unique_ptr<std::uniform_int_distribution<int>> distribution);
        virtual int Value(int index) const override;
    private:
        std::unique_ptr<std::default_random_engine> generator_;
        std::unique_ptr<std::uniform_int_distribution<int>> distribution_;
    };


    class SquaredFill : public ArrayFill {
    public:
        SquaredFill();
        SquaredFill(std::initializer_list<int> elements);
        virtual int Value(int index) const override;
    private:
        int a_;
        int b_;
    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);
}



#endif //JIMP_EXERCISES_ARRAYFILL_H
