#include<iostream>
#include<queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // Function to build tree from user input
    TreeNode* buildTree() {
        cout << "Enter data (-1 for NULL): ";
        int data;
        cin >> data;

        if (data == -1) return nullptr;

        TreeNode* node = new TreeNode(data);

        // Recursively build left and right subtrees
        cout << "Enter left child of " << data << endl;
        node->left = buildTree();
        cout << "Enter right child of " << data << endl;
        node->right = buildTree();

        return node;
    }

    // Level Order Traversal with line breaks
    void levelOrder(TreeNode* node) {
        if (!node) return;

        queue<TreeNode*> q;
        q.push(node);
        q.push(nullptr); 

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == nullptr) {
                cout << endl;  
                if (!q.empty()) q.push(nullptr); 
            } else {
                cout << front->data << " ";
                // Push left and right children if they exist
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }
    }

    // Print all left boundary nodes excluding leaf nodes
    void printLeftEdge(TreeNode* node) {
        if (node == nullptr) return;

        // Stop at leaf node
        if (node->left == nullptr && node->right == nullptr) return;

        cout << node->data << " "; // Print current node

        // Recurse towards left if possible, else go right
        if (node->left)
            printLeftEdge(node->left);
        else
            printLeftEdge(node->right);
    }

    // Print all right boundary nodes (excluding leaves) in **bottom-up** order
    void printRightEdge(TreeNode* node) {
        if (node == nullptr) return;

        // Stop at leaf node
        if (node->left == nullptr && node->right == nullptr) return;

        // First go deep, then print (for bottom-up)
        if (node->right)
            printRightEdge(node->right);
        else
            printRightEdge(node->left);

        cout << node->data << " ";
    }

    // Print all leaf nodes (L to R)
    void printLeafNodes(TreeNode* node) {
        if (node == nullptr) return;

        // If it's a leaf node, print it
        if (node->left == nullptr && node->right == nullptr) {
            cout << node->data << " ";
            return;
        }

        // Recurse to both subtrees
        printLeafNodes(node->left);
        printLeafNodes(node->right);
    }

    //  print full boundary in correct order
    void printBoundaryTraversal(TreeNode* node) {
        if (node == nullptr) return;

        cout << node->data << " ";  // 1. Print root

        // 2. Print left boundary (excluding leaves)
        printLeftEdge(node->left);

        // 3. Print all leaf nodes
        printLeafNodes(node->left);  // From left subtree
        printLeafNodes(node->right); // From right subtree

        // 4. Print right boundary (excluding leaves), bottom-up
        printRightEdge(node->right);
    }
};

int main() {
    BinaryTree tree;

    tree.root = tree.buildTree();

    cout << "\nLevel Order Traversal:\n";
    tree.levelOrder(tree.root);

    cout << "\n\nBoundary Traversal:\n";
    tree.prin
