//
// Created by karol on 5/11/17.
//

#include <algorithm>
#include "Algo.h"

namespace algo {

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy_n(v.begin(), n_elements, std::back_inserter(*out));
    }

    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> sk;
        std::transform(m.begin(), m.end(), std::inserter(sk, sk.begin()), [](const auto &mp){return mp.first;});
        return sk;
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> v;
        std::transform(m.begin(), m.end(), std::back_inserter(v), [](const auto &mp){return mp.second;});
        return v;
    }

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor) {
        return std::map<std::string, int>();
    }

    void SortInPlace(std::vector<int> *v) {

    }

    std::vector<int> Sort(const std::vector<int> &v) {
        return std::vector<int>();
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {

    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {

    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {

    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> vs;
        std::transform(v.begin(), v.end(), std::back_inserter(vs), [](const auto &el){return std::to_string(el);});
        return vs;
    }

    std::string Join(const std::string &joiner, const std::vector<double> &v) {
        return std::__cxx11::string();
    }

    int Sum(const std::vector<int> &v) {
        return std::accumulate(v.begin(), v.end(), 0);
    }

    int Product(const std::vector<int> &v) {
        return std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    }

    bool Contains(const std::vector<int> &v, int element) {
        auto search = std::find(v.begin(), v.end(), element);
        return search != v.end();
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        auto search = std::find_if(v.begin(), v.end(), [&key](const auto &el){return el.first == key;});
        return search != v.end();
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        auto search = std::find_if(v.begin(), v.end(), [&value](const auto &el){return el.second == value;});
        return search != v.end();
    }

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        return std::vector<std::string>();
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {

    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill(v->begin(), v->end(), initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> v;
        std::fill_n(std::back_inserter(v), length, initial_value);
        return v;
    }

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
        return 0;
    }
}