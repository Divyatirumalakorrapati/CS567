#include "deepstate/DeepState.hpp"
#include "AVLTree.cpp"

using namespace deepstate;

TEST(AVLTreeFuzzing, InsertAndRemove) {
    AVLTree<int> tree;

    for (int i = 0; i < 100; ++i) {
        int value = DeepState_Int();  // Generate random integers
        tree.insert(value);
        ASSERT(tree.isBalanced()) << "Tree became unbalanced after insertion.";

        if (i % 2 == 0) {  // Occasionally remove values
            tree.remove(value);
            ASSERT(tree.isBalanced()) << "Tree became unbalanced after removal.";
        }
    }
}
