//
// Created by karol on 5/25/17.
//

#include "Tree.h"
#include <iostream>

using namespace tree;

int main() {
    Tree<int> t(11);
    t.Insert(15);
    t.Insert(7);
    t.Insert(13);
    t.Insert(12);
    t.PrintTreeInOrder();

    return 0;
}