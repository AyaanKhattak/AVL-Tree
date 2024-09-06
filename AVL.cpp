#include "AVL.h"
#include <iostream>
using namespace std;

// Helper function to get the height of a node
int AVL::getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Helper function to calculate balance factor of a node
int AVL::getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Right rotation to balance the tree
Node* AVL::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left rotation to balance the tree
Node* AVL::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Left-Right rotation to balance the tree
Node* AVL::rotateLeftRight(Node* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

// Right-Left rotation to balance the tree
Node* AVL::rotateRightLeft(Node* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

// Balance the node
Node* AVL::balanceNode(Node* node) {
    int balance = getBalanceFactor(node);

    if (balance > 1) {
        if (getBalanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1) {
        if (getBalanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// Insert a new key into the AVL tree
Node* AVL::insertNode(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    return balanceNode(node);
}

// Delete a key from the AVL tree
Node* AVL::deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else {
            Node* temp = getMinValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;

    return balanceNode(root);
}

// Get the node with the smallest value
Node* AVL::getMinValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Search for a node with a specific key
Node* AVL::searchNode(Node* node, int key) {
    if (node == nullptr || node->key == key)
        return node;

    if (key < node->key)
        return searchNode(node->left, key);
    return searchNode(node->right, key);
}

// Inorder traversal
void AVL::inorderTraversal(Node* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        cout << node->key << " ";
        inorderTraversal(node->right);
    }
}

// Preorder traversal
void AVL::preorderTraversal(Node* node) {
    if (node != nullptr) {
        cout << node->key << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

// Postorder traversal
void AVL::postorderTraversal(Node* node) {
    if (node != nullptr) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->key << " ";
    }
}

// Calculate height of the AVL tree
int AVL::calculateHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return max(calculateHeight(node->left), calculateHeight(node->right)) + 1;
}

// Calculate the diameter of the AVL tree
int AVL::calculateDiameter(Node* node, int& height) {
    if (node == nullptr) {
        height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int ldiameter = calculateDiameter(node->left, lh);
    int rdiameter = calculateDiameter(node->right, rh);

    height = max(lh, rh) + 1;

    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

// Find the successor of a node
Node* AVL::findSuccessor(Node* node) {
    if (node == nullptr || node->right == nullptr)
        return nullptr;

    Node* current = node->right;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Find the predecessor of a node
Node* AVL::findPredecessor(Node* node) {
    if (node == nullptr || node->left == nullptr)
        return nullptr;

    Node* current = node->left;
    while (current->right != nullptr)
        current = current->right;
    return current;
}

// Public insert function
void AVL::insert(int key) {
    root = insertNode(root, key);
}

// Public remove function
void AVL::remove(int key) {
    root = deleteNode(root, key);
}

// Public search function
bool AVL::search(int key) {
    return searchNode(root, key) != nullptr;
}

// Public inorder traversal function
void AVL::inorder() {
    inorderTraversal(root);
    cout << endl;
}

// Public preorder traversal function
void AVL::preorder() {
    preorderTraversal(root);
    cout << endl;
}

// Public postorder traversal function
void AVL::postorder() {
    postorderTraversal(root);
    cout << endl;
}

// Public height function
int AVL::height() {
    return calculateHeight(root);
}

// Public diameter function
int AVL::diameter() {
    int height = 0;
    return calculateDiameter(root, height);
}

// Public find minimum function
int AVL::findMin() {
    Node* minNode = getMinValueNode(root);
    if (minNode == nullptr)
        return -1;  // Tree is empty
    return minNode->key;
}

// Public find maximum function
int AVL::findMax() {
    Node* maxNode = root;
    while (maxNode != nullptr && maxNode->right != nullptr)
        maxNode = maxNode->right;
    if (maxNode == nullptr)
        return -1;  // Tree is empty
    return maxNode->key;
}

// Public find successor function
int AVL::successor(int key) {
    Node* node = searchNode(root, key);
    if (node == nullptr)
        return -1;  // Key not found
    Node* successorNode = findSuccessor(node);
    if (successorNode == nullptr)
        return -1;  // Successor not found
    return successorNode->key;
}

// Public find predecessor function
int AVL::predecessor(int key) {
    Node* node = searchNode(root, key);
    if (node == nullptr)
        return -1;  // Key not found
    Node* predecessorNode = findPredecessor(node);
    if (predecessorNode == nullptr)
        return -1;  // Predecessor not found
    return predecessorNode->key;
}
