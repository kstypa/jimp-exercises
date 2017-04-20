//
// Created by karol on 4/20/17.
//

#include <algorithm>
#include <iostream>
#include "WordCounter.h"

namespace datastructures {

    //counts

    Counts::Counts() : count_(0) {}

    Counts::Counts(int count) {
        count_ = count;
    }

    int Counts::GetCount() const {
        return count_;
    }

    bool Counts::operator<(const Counts &rhs) const {
        return count_ < rhs.count_;
    }

    bool Counts::operator>(const Counts &rhs) const {
        return rhs < *this;
    }

    bool Counts::operator<=(const Counts &rhs) const {
        return !(rhs < *this);
    }

    bool Counts::operator>=(const Counts &rhs) const {
        return !(*this < rhs);
    }

    bool Counts::operator==(const Counts &rhs) const {
        return count_ == rhs.count_;
    }

    bool Counts::operator!=(const Counts &rhs) const {
        return !(rhs == *this);
    }

    Counts &Counts::operator++() {
        ++count_;
        return *this;
    }

    Counts Counts::operator++(int) {
        Counts tmp(*this);
        operator++();
        return tmp;
    }

    //word

    Word::Word() : word_() {}

    Word::Word(std::string str) {
        word_ = str;
    }

    std::string Word::GetString() const {
        return word_;
    }

    bool Word::operator==(const Word &rhs) const {
        return word_ == rhs.word_;
    }

    bool Word::operator!=(const Word &rhs) const {
        return !(rhs == *this);
    }

    bool Word::operator<(const Word &rhs) const {
        return word_ < rhs.word_;
    }

    bool Word::operator>(const Word &rhs) const {
        return rhs < *this;
    }

    bool Word::operator<=(const Word &rhs) const {
        return !(rhs < *this);
    }

    bool Word::operator>=(const Word &rhs) const {
        return !(*this < rhs);
    }

    //word counter

    WordCounter::WordCounter() : words_(), total_(0), counter_() {}

    WordCounter::WordCounter(const std::initializer_list<Word> elements) : words_(elements), total_(elements.size()) {
        for(auto n : elements){
            auto it = std::find_if(counter_.begin(), counter_.end(), [&n](const std::pair<Word, Counts> &element){return element.first == n;});
            if(it == counter_.end())
                counter_.insert(std::make_pair(n,Counts(1)));
            else {
                auto copy = std::make_pair(n, it->second);
                ++copy.second;
                counter_.erase(it);
                counter_.insert(copy);
            }
        }
    }

    size_t WordCounter::DistinctWords() const {
        return words_.size();
    }

    size_t WordCounter::TotalWords() const {
        return total_;
    }

    std::set<Word> WordCounter::Words() const {
        return words_;
    }

    int WordCounter::operator[](std::string str) const {
        int count = 0;
        for(auto n : counter_){
            if(n.first == Word(str))
                count = n.second.GetCount();
        }
        return count;
    }

    struct {
        bool operator()(const std::pair<Word, Counts> &a, const std::pair<Word, Counts> &b)
        {
            return a.second.GetCount() > b.second.GetCount();
        }
    } CmpCount;

    std::ostream &operator<<(std::ostream &os, const WordCounter &wc) {
        std::vector<std::pair<Word, Counts>> sortedcounter(wc.counter_.begin(), wc.counter_.end());
        std::sort(sortedcounter.begin(), sortedcounter.end(), CmpCount);
        for(auto n : sortedcounter)
            os << "word: " << n.first.GetString() << " count: " << n.second.GetCount() << std::endl;
        return os;
    }
}