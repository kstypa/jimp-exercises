//
// Created by karol on 5/25/17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>
#include <iostream>

namespace tree {

    template<class T>
    class Tree {
    public:
        Tree() {};
        Tree(const T &value_);
        Tree(Tree<T> &&t);

        void Insert(T value);
        void InsertIterative(T value);
        void PrintTreeInOrder() const;

    private:
        T value_;
        std::unique_ptr<Tree<T>> left_;
        std::unique_ptr<Tree<T>> right_;

        void InsertIntoLeftSubTree(T value);

        void InsertIntoRightSubTree(T value);
    };

    template<class T>
    Tree<T>::Tree(const T &value_) : value_(value_) {

    }

    template<class T>
    Tree<T>::Tree(Tree<T> &&t) : value_(t.value_), left_(std::move(t.left_)), right_(std::move(t.right_)) {

    }

    template<class T>
    void Tree<T>::Insert(T value) {
        if(value < value_)
            InsertIntoLeftSubTree(value);
        else
            InsertIntoRightSubTree(value);
    }

    template<class T>
    void Tree<T>::InsertIntoLeftSubTree(T value) {
        if(left_)
            left_->Insert(value);
        else
            left_ = std::make_unique<Tree<T>>(value);
    }

    template<class T>
    void Tree<T>::InsertIntoRightSubTree(T value) {
        if(right_)
            right_->Insert(value);
        else
            right_ = std::make_unique<Tree<T>>(value);
    }

    template<class T>
    void Tree<T>::InsertIterative(T value) {
        Tree<T> *current = this;
        while(current != nullptr) {
            if(value < current->value_) {
                if(current->left_)
                    current = current->left_.get();
                else {
                    current->left_ = std::make_unique<Tree<T>>(value);
                    break;
                }
            }
            else {
                if(current->right_)
                    current = current->right_.get();
                else {
                    current->right_ = std::make_unique<Tree<T>>(value);
                    break;
                }
            }
        }
    }

    template<class T>
    void Tree<T>::PrintTreeInOrder() const {
        if(left_ != nullptr)
            left_->PrintTreeInOrder();
        std::cout << value_ << std::endl;
        if(right_ != nullptr)
            right_->PrintTreeInOrder();
    }

}


#endif //JIMP_EXERCISES_TREE_H
