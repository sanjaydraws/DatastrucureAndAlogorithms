#include <iostream>
#include <queue>
#include <map>
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

    TreeNode* buildTree() {
        cout << "Enter data (-1 for NULL): ";
        int val;
        cin >> val;
        if (val == -1) return nullptr;

        TreeNode* node = new TreeNode(val);
        cout << "Enter left child of " << val << endl;
        node->left = buildTree();
        cout << "Enter right child of " << val << endl;
        node->right = buildTree();

        return node;
    }

    void levelOrder(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);  // Level separator

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

    void printTopView(TreeNode* root) {
        map<int, int> topNodes;  // HD -> Node data
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front(); q.pop();

            if (topNodes.find(hd) == topNodes.end()) {
                topNodes[hd] = node->data;  // First node at that HD
            }

            if (node->left)  q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        cout << "\nTop View: ";
        for (auto& [hd, val] : topNodes) {
            cout << val << " ";
        }
        cout << endl;
    }

    void printBottomView(TreeNode* root) {
        map<int, int> bottomNodes;  // HD -> Node data
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front(); q.pop();

            bottomNodes[hd] = node->data;  // Overwrite for bottom-most node

            if (node->left)  q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        cout << "Bottom View: ";
        for (auto& [hd, val] : bottomNodes) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTree* tree = new BinaryTree();
    tree->root = tree->buildTree();

    cout << "\nLevel Order Traversal:\n";
    tree->levelOrder(tree->root);

    tree->printTopView(tree->root);
    tree->printBottomView(tree->root);

       return 0;
}
