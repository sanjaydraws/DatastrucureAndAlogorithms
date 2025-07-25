#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Tree node class representing each node of the binary tree
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root = nullptr; // Root of the tree
    unordered_map<int, int> inorderIndexMap; // Maps node values to their indices in inorder traversal

    // Recursive helper function to build the binary tree
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                              int inStart, int inEnd, int& preorderIndex) {
        // Base case: no subtree to build
        if (inStart > inEnd) return nullptr;

        // Pick current node from preorder using preorderIndex and increment it
        int rootVal = preorder[preorderIndex++];
        TreeNode* node = new TreeNode(rootVal);

        // Get the index of this node in inorder traversal
        int inIndex = inorderIndexMap[rootVal];

        // Recursively build left and right subtrees
        node->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preorderIndex);
        node->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preorderIndex);

        return node;
    }

public:
    // Builds tree from preorder and inorder traversals and returns the root
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderIndexMap.clear();

        // Fill the map with inorder element -> index for O(1) access
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        int preorderIndex = 0;
        root = buildTreeHelper(preorder, inorder, 0, inorder.size() - 1, preorderIndex);
        return root;
    }

    // ✅ Level Order Traversal (prints each level in a new line using nullptr marker)
    void printLevelOrderByMarker() {
        if (!root) return;

        cout << "Level Order Traversal:\n";
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);  // Marker to indicate end of a level

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                cout << endl; // End of current level
                if (!q.empty()) q.push(nullptr); // Push new marker if next level exists
            } else {
                cout << curr->val << " ";
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
    }
};

int main() {
    // Input traversals
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    BinaryTree bt;
    bt.buildTree(preorder, inorder);         // Build the tree from given traversals
    bt.printLevelOrderByMarker();            // Print tree level by level

    return 0;
}

