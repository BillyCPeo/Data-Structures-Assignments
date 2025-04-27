/*Billy Peo
April 18 2025 
Data Structures
Professor Heng*/

#include <iostream>
using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper: Find node by value
TreeNode* findNode(TreeNode* T, int x) {
    if (T == nullptr) return nullptr;
    if (x < T->val) return findNode(T->left, x);
    if (x > T->val) return findNode(T->right, x);
    return T;
}

// Left Rotation around the node with value `node`
int leftrotation(int node, TreeNode*& T) {
    TreeNode* parent = nullptr;
    TreeNode* cur = T;

    // Find the node and its parent
    while (cur != nullptr && cur->val != node) {
        parent = cur;
        if (node < cur->val) cur = cur->left;
        else cur = cur->right;
    }

    if (cur == nullptr || cur->right == nullptr) {
        // Cannot rotate if node doesn't exist or has no right child
        return 0;
    }

    TreeNode* newRoot = cur->right;
    cur->right = newRoot->left;
    newRoot->left = cur;

    if (parent == nullptr) {
        // Node was the root
        T = newRoot;
    }
    else {
        if (parent->left == cur) parent->left = newRoot;
        else parent->right = newRoot;
    }
    return 1;
}

// Right Rotation around the node with value `node`
int rightrotation(int node, TreeNode*& T) {
    TreeNode* parent = nullptr;
    TreeNode* cur = T;

    // Find the node and its parent
    while (cur != nullptr && cur->val != node) {
        parent = cur;
        if (node < cur->val) cur = cur->left;
        else cur = cur->right;
    }

    if (cur == nullptr || cur->left == nullptr) {
        // Cannot rotate if node doesn't exist or has no left child
        return 0;
    }

    TreeNode* newRoot = cur->left;
    cur->left = newRoot->right;
    newRoot->right = cur;

    if (parent == nullptr) {
        // Node was the root
        T = newRoot;
    }
    else {
        if (parent->left == cur) parent->left = newRoot;
        else parent->right = newRoot;
    }
    return 1;
}

// Optional: Helper function for inorder traversal
void inorderTraversal(TreeNode* T) {
    if (T == nullptr) return;
    inorderTraversal(T->left);
    cout << T->val << " ";
    inorderTraversal(T->right);
}
// Helper to print tree visually (indent levels)
void printTree(TreeNode* T, int space = 0, int height = 10) {
    if (T == nullptr) return;

    space += height;

    printTree(T->right, space);

    cout << endl;
    for (int i = height; i < space; i++)
        cout << " ";
    cout << T->val << "\n";

    printTree(T->left, space);
}

// Example usage
int main() {
    TreeNode* T = nullptr;

    // Build a simple tree manually
    T = new TreeNode(30);
    T->left = new TreeNode(20);
    T->right = new TreeNode(40);
    T->right->right = new TreeNode(50);

    cout << "Original Tree:\n";
    printTree(T);

    // Perform left rotation at 30
    leftrotation(30, T);
    cout << "\nAfter Left Rotation at 30:\n";
    printTree(T);

    // Perform right rotation at 40
    rightrotation(40, T);
    cout << "\nAfter Right Rotation at 40:\n";
    printTree(T);

    return 0;
}


