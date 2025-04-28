/*Billy Peo
* 4/28/24
* Data Structures
* Professor Heng
*/
#include <iostream>
using namespace std;

#define MIN_DEGREE 2  // Minimum degree t (you can adjust)

class BminusTreeNode {
public:
    int keys[2 * MIN_DEGREE - 1];
    BminusTreeNode* children[2 * MIN_DEGREE];
    int n;          // Current number of keys
    bool leaf;      // True if node is a leaf

    BminusTreeNode(bool _leaf);
    void insertNonFull(int key);
    void splitChild(int i, BminusTreeNode* y);
    void traverse(); // For testing
    friend class BminusTree;
};

class BminusTree {
public:
    BminusTreeNode* root;

    BminusTree() {
        root = nullptr;
    }

    void insert(int key);
    void traverse() {
        if (root != nullptr) root->traverse();
    }
};

BminusTreeNode::BminusTreeNode(bool _leaf) {
    leaf = _leaf;
    n = 0;
    for (int i = 0; i < 2 * MIN_DEGREE; i++) {
        children[i] = nullptr;
    }
}

void BminusTree::insert(int key) {
    if (root == nullptr) {
        root = new BminusTreeNode(true);
        root->keys[0] = key;
        root->n = 1;
    }
    else {
        if (root->n == 2 * MIN_DEGREE - 1) {
            BminusTreeNode* s = new BminusTreeNode(false);
            s->children[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < key) {
                i++;
            }
            s->children[i]->insertNonFull(key);
            root = s;
        }
        else {
            root->insertNonFull(key);
        }
    }
}

void BminusTreeNode::insertNonFull(int key) {
    int i = n - 1;
    if (leaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        n += 1;
    }
    else {
        while (i >= 0 && keys[i] > key) {
            i--;
        }
        i++;
        if (children[i]->n == 2 * MIN_DEGREE - 1) {
            splitChild(i, children[i]);
            if (keys[i] < key) {
                i++;
            }
        }
        children[i]->insertNonFull(key);
    }
}

void BminusTreeNode::splitChild(int i, BminusTreeNode* y) {
    BminusTreeNode* z = new BminusTreeNode(y->leaf);
    z->n = MIN_DEGREE - 1;

    for (int j = 0; j < MIN_DEGREE - 1; j++) {
        z->keys[j] = y->keys[j + MIN_DEGREE];
    }

    if (!y->leaf) {
        for (int j = 0; j < MIN_DEGREE; j++) {
            z->children[j] = y->children[j + MIN_DEGREE];
        }
    }

    y->n = MIN_DEGREE - 1;

    for (int j = n; j >= i + 1; j--) {
        children[j + 1] = children[j];
    }
    children[i + 1] = z;

    for (int j = n - 1; j >= i; j--) {
        keys[j + 1] = keys[j];
    }
    keys[i] = y->keys[MIN_DEGREE - 1];

    n += 1;
}

void BminusTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) {
            children[i]->traverse();
        }
        cout << " " << keys[i];
    }
    if (!leaf) {
        children[i]->traverse();
    }
}

int main() {
    BminusTree t;

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of B- tree is:\n";
    t.traverse();
    cout << endl;

    return 0;
}
