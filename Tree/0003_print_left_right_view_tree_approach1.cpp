#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

// Node structure of the Binary Tree
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

    // Recursive function to build binary tree from user input
    TreeNode* createTree() {
        cout << "Enter data (-1 for NULL): ";
        int data;
        cin >> data;

        // Base case: -1 means no node (NULL)
        if (data == -1) return nullptr;

        TreeNode* node = new TreeNode(data);

        // Recursively build left and right subtree
        cout << "Enter left child of " << data << endl;
        node->left = createTree();
        cout << "Enter right child of " << data << endl;
        node->right = createTree();

        return node;
    }

    // Level Order Traversal (Breadth-First Search), Line by Line
    void levelOrderTraversal(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);  // Marker for new level

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == nullptr) {
                cout << endl;
                if (!q.empty()) q.push(nullptr);  // New level marker
            } else {
                cout << front->data << " ";
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }
    }

    // Left View using Level Order Traversal (BFS)
    void leftView(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front(); q.pop();

                // Print the first node of each level
                if (i == 0) cout << curr->data << " ";

                // Push children for next level
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
    }

    // Right View using Level Order Traversal (BFS)
    void rightView(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front(); q.pop();

                // Print the last node of each level
                if (i == levelSize - 1) cout << curr->data << " ";

                // Push children for next level
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
    }
};

int main() {
    BinaryTree* tree = new BinaryTree();

    // Build tree from user input
    tree->root = tree->createTree();

    // Print all traversals and views
    cout << "\nLevel Order Traversal:\n";
    tree->levelOrderTraversal(tree->root);

    cout << "\nLeft View (Level Order): ";
    tree->leftView(tree->root);

    cout << "\nRight View (Level Order): ";
    tree->rightView(tree->root);

    return 0;
}
