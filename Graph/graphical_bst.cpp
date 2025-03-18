#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

// Node structure for the BST
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = right = nullptr;
    }
};

// Binary Search Tree Class
class BST {
private:
    Node* root;

    // Helper function for insertion
    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        return node;
    }

    // Helper function for searching
    bool search(Node* node, int key) {
        if (!node) return false;
        if (node->key == key) return true;
        if (key < node->key)
            return search(node->left, key);
        return search(node->right, key);
    }

    // Helper function for graphical tree display
    void display(Node* root, int space) {
        if (!root) return;

        // Increase distance between levels
        space += 5;

        // Print right child first
        display(root->right, space);

        // Print current node after space count
        cout << endl;
        for (int i = 5; i < space; i++)
            cout << " ";
        cout << root->key << "\n";

        // Print left child
        display(root->left, space);
    }

public:
    BST() { root = nullptr; }

    // Public insert function
    void insert(int key) {
        root = insert(root, key);
    }

    // Public search function
    bool search(int key) {
        return search(root, key);
    }

    // Public display function
    void display() {
        display(root, 0);
    }
};

// Driver Code
int main() {
    BST tree;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.insert(x);
        cout << "Inserted: " << x << endl;
        tree.display();
        cout << endl;
    }
}
