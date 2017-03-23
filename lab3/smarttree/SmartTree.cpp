//
// Created by karol on 3/23/17.
//

#include "SmartTree.h"
using ::std::unique_ptr;
using ::std::string;
using ::std::ostream;
using ::std::make_unique;
using ::std::move;

namespace datastructures {
    unique_ptr <SmartTree> CreateLeaf(int value){
        auto leaf = make_unique<SmartTree>();
        leaf->left = nullptr;
        leaf->right = nullptr;
        leaf->value = value;
        return leaf;
    }

    unique_ptr <SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree){
        auto root = move(tree);
        root->left = move(left_subtree);
        return root;
    }

    unique_ptr <SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree){
        auto root = move(tree);
        root->right = move(right_subtree);
        return root;
    }

    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, ostream *out){
        if(unique_ptr->left != nullptr)
            PrintTreeInOrder(unique_ptr->left, out);
        *out << unique_ptr->value << ", ";
        if(unique_ptr->right != nullptr)
            PrintTreeInOrder(unique_ptr->right, out);
    }

    string DumpTree(const unique_ptr<SmartTree> &tree){
        if(tree == nullptr)
            return "[none]";
        string dump;
        dump += "[" + std::to_string(tree->value) + " " + DumpTree(tree->left) + " " + DumpTree(tree->right) + "]";
        return dump;
    }

    unique_ptr <SmartTree> RestoreTree(const string &tree){
        string value;
        for(auto ch : tree){
            if((tree[tree.find(ch)-1] == '[' || isdigit(tree[tree.find(ch)-1])) && ch != ']' && ch != ' '){
                value += ch;
                if(value == "none")
                    return nullptr;
            }
        }
        auto leaf = make_unique<SmartTree>();
        leaf->value = std::stoi(value);
        value = "";
        return leaf;
    }
}