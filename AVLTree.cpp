#include "AVLTree.h"

template <typename T>
class AVLTree {
private:
    AVLNode<T>* root;

    // Helper: Get height of a node
    int getHeight(AVLNode<T>* node) {
        return node ? node->height : 0;
    }

    // Helper: Update the height of a node
    void updateHeight(AVLNode<T>* node) {
        if (node) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }

    // Helper: Get the balance factor of a node
    int getBalanceFactor(AVLNode<T>* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Rotate Right
    AVLNode<T>* rotateRight(AVLNode<T>* y) {
        AVLNode<T>* x = y->left;
        AVLNode<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Rotate Left
    AVLNode<T>* rotateLeft(AVLNode<T>* x) {
        AVLNode<T>* y = x->right;
        AVLNode<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Balance the node
    AVLNode<T>* balance(AVLNode<T>* node) {
        if (!node) return node;

        updateHeight(node);

        int balanceFactor = getBalanceFactor(node);

        // Left-heavy
        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }

        // Right-heavy
        if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    // Helper: Insert recursively
    AVLNode<T>* insert(AVLNode<T>* node, T value) {
        if (!node) return new AVLNode<T>(value);

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            return node;  // Duplicate values not allowed
        }

        return balance(node);
    }

    // Helper: Find the minimum node
    AVLNode<T>* findMin(AVLNode<T>* node) {
        return node->left ? findMin(node->left) : node;
    }

    // Helper: Remove recursively
    AVLNode<T>* remove(AVLNode<T>* node, T value) {
        if (!node) return node;

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // Node to be deleted
            if (!node->left || !node->right) {
                AVLNode<T>* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            } else {
                AVLNode<T>* temp = findMin(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        return balance(node);
    }

    // Helper: In-order traversal
    void inOrder(AVLNode<T>* node) {
        if (node) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Helper: Check if tree is balanced
    bool isBalancedHelper(AVLNode<T>* node) {
        if (!node) return true;

        int balanceFactor = getBalanceFactor(node);
        return std::abs(balanceFactor) <= 1 &&
               isBalancedHelper(node->left) &&
               isBalancedHelper(node->right);
    }

public:
    // Constructor
    AVLTree() : root(nullptr) {}

    // Insert a value
    void insert(T value) {
        root = insert(root, value);
    }

    // Remove a value
    void remove(T value) {
        root = remove(root, value);
    }

    // In-order traversal
    void inOrder() {
        inOrder(root);
        std::cout << std::endl;
    }

    // Check if tree is balanced
    bool isBalanced() {
        return isBalancedHelper(root);
    }
};

#endif  // AVLTREE_H
