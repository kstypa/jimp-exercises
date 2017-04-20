//
// Created by karol on 4/20/17.
//

#include "WordCounter.h"
#include <iostream>

using namespace datastructures;
using ::std::cout;
using ::std::endl;

int main() {
    WordCounter wc {Word("a"), Word("b"), Word("a")};
    cout << endl << "total " << wc.TotalWords() << endl << "distinct " << wc.DistinctWords() << endl;

    return 0;
}