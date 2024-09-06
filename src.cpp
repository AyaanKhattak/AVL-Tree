#include <iostream>
#include "AVL.h"

using namespace std;

void printSeparator() {
    cout << "----------------------------------------" << endl;
}

int main() {
    AVL tree;

    // Insert nodes
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(10);
    tree.insert(25);
    tree.insert(35);
    tree.insert(45);
    tree.insert(55);
    tree.insert(65);
    tree.insert(75);
    tree.insert(85);

    // Display tree information
    cout << "AVL Tree Operations Demo" << endl;
    printSeparator();

    cout << "Initial AVL Tree:" << endl;
    cout << "Inorder traversal: ";
    tree.inorder();
    cout << "Preorder traversal: ";
    tree.preorder();
    cout << "Postorder traversal: ";
    tree.postorder();
    cout << "Height of the AVL tree: " << tree.height() << endl;
    cout << "Diameter of the AVL tree: " << tree.diameter() << endl;
    cout << "Minimum value in the AVL tree: " << tree.findMin() << endl;
    cout << "Maximum value in the AVL tree: " << tree.findMax() << endl;
    printSeparator();

    // Perform more operations
    cout << "Performing additional operations:" << endl;
    tree.insert(90);
    tree.insert(95);
    cout << "Inserted values 90 and 95." << endl;
    printSeparator();

    // Search operation
    int searchKey = 65;
    cout << "Searching for key " << searchKey << ": ";
    if (tree.search(searchKey))
        cout << "Found." << endl;
    else
        cout << "Not found." << endl;
    printSeparator();

    // Successor and Predecessor operations
    int successorKey = 70;
    int successor = tree.successor(successorKey);
    if (successor != -1)
        cout << "Successor of " << successorKey << " is: " << successor << endl;
    else
        cout << "Successor of " << successorKey << " not found." << endl;

    int predecessorKey = 75;
    int predecessor = tree.predecessor(predecessorKey);
    if (predecessor != -1)
        cout << "Predecessor of " << predecessorKey << " is: " << predecessor << endl;
    else
        cout << "Predecessor of " << predecessorKey << " not found." << endl;
    printSeparator();

    // Deletion operations
    tree.remove(40);
    tree.remove(20);
    cout << "Deleted nodes with keys 40 and 20." << endl;
    cout << "Inorder traversal after deletions: ";
    tree.inorder();
    printSeparator();

    // Final tree information
    cout << "Final AVL Tree:" << endl;
    cout << "Inorder traversal: ";
    tree.inorder();
    cout << "Preorder traversal: ";
    tree.preorder();
    cout << "Postorder traversal: ";
    tree.postorder();
    cout << "Height of the AVL tree: " << tree.height() << endl;
    cout << "Diameter of the AVL tree: " << tree.diameter() << endl;
    cout << "Minimum value in the AVL tree: " << tree.findMin() << endl;
    cout << "Maximum value in the AVL tree: " << tree.findMax() << endl;
    printSeparator();

    return 0;
}
