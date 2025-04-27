/*Billy Peo
Data Structures
April 10 2025
Professor Heng*/

#include <iostream>
using namespace std;

// Definition of a BST node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert x into BST T
int InsertBST(int x, TreeNode*& T) {
    if (T == nullptr) {
        T = new TreeNode(x);
        return 1;
    }
    if (x < T->val) {
        return InsertBST(x, T->left);
    }
    else if (x > T->val) {
        return InsertBST(x, T->right);
    }
    else {
        // Duplicate value, do not insert
        return 0;
    }
}

// Helper to find minimum node in right subtree
TreeNode* findMin(TreeNode* T) {
    while (T && T->left) {
        T = T->left;
    }
    return T;
}

// Delete x from BST T
int DeleteBST(int x, TreeNode*& T) {
    if (T == nullptr) {
        return 0; // Not found
    }
    if (x < T->val) {
        return DeleteBST(x, T->left);
    }
    else if (x > T->val) {
        return DeleteBST(x, T->right);
    }
    else {
        // Node found
        if (T->left && T->right) {
            // Two children: replace with inorder successor
            TreeNode* temp = findMin(T->right);
            T->val = temp->val;
            return DeleteBST(temp->val, T->right);
        }
        else {
            // One child or no child
            TreeNode* temp = T;
            if (T->left) {
                T = T->left;
            }
            else {
                T = T->right;
            }
            delete temp;
            return 1;
        }
    }
}

// Optional: Helper function to print inorder traversal
void inorderTraversal(TreeNode* T) {
    if (T == nullptr) return;
    inorderTraversal(T->left);
    cout << T->val << " ";
    inorderTraversal(T->right);
}

// Optional: Free all nodes in the tree
void freeTree(TreeNode* T) {
    if (T == nullptr) return;
    freeTree(T->left);
    freeTree(T->right);
    delete T;
}

// Example usage
int main() {
    TreeNode* T = nullptr;

    InsertBST(50, T);
    InsertBST(30, T);
    InsertBST(70, T);
    InsertBST(20, T);
    InsertBST(40, T);
    InsertBST(60, T);
    InsertBST(80, T);

    cout << "Inorder traversal after insertion: ";
    inorderTraversal(T);
    cout << endl;

    DeleteBST(20, T); // Deleting leaf node
    DeleteBST(30, T); // Deleting node with one child
    DeleteBST(50, T); // Deleting node with two children

    cout << "Inorder traversal after deletion: ";
    inorderTraversal(T);
    cout << endl;

    freeTree(T); // Clean up memory
    return 0;
}
