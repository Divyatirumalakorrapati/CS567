#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <algorithm>  // For std::max

template <typename T>
class AVLNode {
public:
    T data;
    AVLNode* left;
    AVLNode* right;
    int height;

    // Constructor
    AVLNode(T value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

#endif  // AVLTREE_H
