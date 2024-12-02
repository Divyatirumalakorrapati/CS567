#include "AVLTree.cpp"
#include <cassert>

void testInsert() {
    AVLTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);

    // Basic checks
    assert(tree.isBalanced() == true);
    std::cout << "testInsert passed!" << std::endl;
}

void testRemove() {
    AVLTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.remove(10);

    // Basic checks
    assert(tree.isBalanced() == true);
    std::cout << "testRemove passed!" << std::endl;
}

int main() {
    testInsert();
    testRemove();
    return 0;
}
