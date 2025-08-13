#include<iostream>
#include<queue>
#include<map>
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

    void levelOrderTraversal(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

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

    // Recursive Top View
    void topViewDFS(TreeNode* root, int hd, int level, map<int, pair<int, int>>& topMap) {
        if (!root) return;

        if (topMap.find(hd) == topMap.end() || level < topMap[hd].second) {
            topMap[hd] = {root->data, level};
        }

        topViewDFS(root->left, hd - 1, level + 1, topMap);
        topViewDFS(root->right, hd + 1, level + 1, topMap);
    }

    void topView(TreeNode* root) {
        map<int, pair<int, int>> topMap;
        topViewDFS(root, 0, 0, topMap);
        cout << "Top View: ";
        for (auto& entry : topMap) {
            cout << entry.second.first << " ";
        }
        cout << endl;
    }

    // Recursive Bottom View
    void bottomViewDFS(TreeNode* root, int hd, int level, map<int, pair<int, int>>& bottomMap) {
        if (!root) return;

        if (bottomMap.find(hd) == bottomMap.end() || level >= bottomMap[hd].second) {
            bottomMap[hd] = {root->data, level};
        }

        bottomViewDFS(root->left, hd - 1, level + 1, bottomMap);
        bottomViewDFS(root->right, hd + 1, level + 1, bottomMap);
    }

    void bottomView(TreeNode* root) {
        map<int, pair<int, int>> bottomMap;
        bottomViewDFS(root, 0, 0, bottomMap);
        cout << "Bottom View: ";
        for (auto& entry : bottomMap) {
            cout << entry.second.first << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTree* tree = new BinaryTree();
    tree->root = tree->createTree();

    cout << "\nLevel Order Traversal:\n";
    tree->levelOrderTraversal(tree->root);

    tree->topView(tree->root);
    tree->bottomView(tree->root);

    return 0;
}
