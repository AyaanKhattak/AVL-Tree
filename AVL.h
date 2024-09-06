#ifndef AVLTREE_H
#define AVLTREE_H

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVL {
private:
    Node* root;

    int getHeight(Node* node);
    int getBalanceFactor(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* rotateLeftRight(Node* node);
    Node* rotateRightLeft(Node* node);
    Node* balanceNode(Node* node);
    Node* insertNode(Node* node, int key);
    Node* deleteNode(Node* node, int key);
    Node* getMinValueNode(Node* node);
    Node* searchNode(Node* node, int key);
    void inorderTraversal(Node* node);
    void preorderTraversal(Node* node);
    void postorderTraversal(Node* node);
    int calculateHeight(Node* node);
    int calculateDiameter(Node* node, int& height);
    Node* findSuccessor(Node* node);
    Node* findPredecessor(Node* node);

public:
    AVL() : root(nullptr) {}
    void insert(int key);
    void remove(int key);
    bool search(int key);
    void inorder();
    void preorder();
    void postorder();
    int height();
    int diameter();
    int findMin();
    int findMax();
    int successor(int key);
    int predecessor(int key);
};

#endif // AVLTREE_H
