#include "AVLTree.cpp"
#include <iostream>

int main() {
    AVLTree<int> tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    std::cout << "In-order traversal of the AVL Tree: ";
    tree.inOrder();

    std::cout << "Removing 20...\n";
    tree.remove(20);

    std::cout << "In-order traversal after removal: ";
    tree.inOrder();

    std::cout << "Is the tree balanced? " << (tree.isBalanced() ? "Yes" : "No") << std::endl;

    return 0;
}
