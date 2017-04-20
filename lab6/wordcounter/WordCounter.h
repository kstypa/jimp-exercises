//
// Created by karol on 4/20/17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <set>
#include <initializer_list>

namespace datastructures {

    class Word {
    public:
        Word();
        Word(std::string str);

        bool operator==(const Word &rhs) const;
        bool operator!=(const Word &rhs) const;
        bool operator<(const Word &rhs) const;
        bool operator>(const Word &rhs) const;
        bool operator<=(const Word &rhs) const;
        bool operator>=(const Word &rhs) const;

    private:
        std::string word_;
    };

    class Counts {
    public:
        Counts();
        Counts(int count);

        int GetCount() const;

        bool operator<(const Counts &rhs) const;
        bool operator>(const Counts &rhs) const;
        bool operator<=(const Counts &rhs) const;
        bool operator>=(const Counts &rhs) const;
        bool operator==(const Counts &rhs) const;
        bool operator!=(const Counts &rhs) const;

        Counts &operator++();
        Counts operator++(int);

    private:
        int count_;
    };

    class WordCounter {
    public:
        WordCounter();
        WordCounter(const std::initializer_list<Word> elements);

        size_t DistinctWords() const;
        size_t TotalWords() const;
        std::set<Word> Words() const;

        int operator[](std::string str) const;

    private:
        std::set<Word> words_;
        size_t total_;
        std::set<std::pair<Word, Counts>> counter_;
    };

}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
