#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Node definition
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BinaryTree class with utility functions
class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // Recursive tree builder
    TreeNode* createTree() {
        cout << "Enter data (-1 for NULL): ";
        int data;
        cin >> data;

        if (data == -1) return nullptr;

        TreeNode* node = new TreeNode(data);

        cout << "Enter left child of " << data << endl;
        node->left = createTree();

        cout << "Enter right child of " << data << endl;
        node->right = createTree();

        return node;
    }

    // Level order traversal with line-by-line output (BFS)
    void levelOrderTraversal(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr); // level marker

        while (!q.empty()) {
            TreeNode* front = q.front();  
            q.pop();

            if (front == nullptr) {
                cout << endl;
                if (!q.empty()) q.push(nullptr);
            } else {
                cout << front->data << " ";
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }
    }

    // ============================================
    // LEFT VIEW USING DFS (Preorder Traversal)
    // - Traverse root->left->right
    // - At each level, if it's the first time we visit that level (view.size() == level),
    //   we push the node's data into view.
    // ============================================
    void leftViewDFS(TreeNode* root, int level, vector<int>& view){
        if (!root) return;

        if (view.size() == level) {
            view.push_back(root->data);
        }

        leftViewDFS(root->left, level + 1, view);
        leftViewDFS(root->right, level + 1, view);
    }

    void leftView(TreeNode* root) {
        vector<int> view;
        leftViewDFS(root, 0, view);

        for (int val : view) {
            cout << val << " ";
        }
        cout << endl;
    }

    // ============================================
    //  RIGHT VIEW USING DFS (Preorder Traversal)
    // - Traverse root->right->left
    // - At each level, if it's the first time we visit that level (view.size() == level),
    //   we push the node's data into view.
    // ============================================
    void rightViewDFS(TreeNode* root, int level, vector<int>& view) {
        if (!root) return;

        if (view.size() == level) {
            view.push_back(root->data);
        }

        rightViewDFS(root->right, level + 1, view);
        rightViewDFS(root->left, level + 1, view);
    }

    void rightView(TreeNode* root) {
        vector<int> view;
        rightViewDFS(root, 0, view);

        for (int val : view) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTree* tree = new BinaryTree();
    tree->root = tree->createTree();  // Build tree

    cout << "\nLevel Order Traversal:\n";
    tree->levelOrderTraversal(tree->root);

    cout << "Left View of Tree (DFS): ";
    tree->leftView(tree->root);

    cout << "Right View of Tree (DFS): ";
    tree->rightView(tree->root);

    return 0;
}
