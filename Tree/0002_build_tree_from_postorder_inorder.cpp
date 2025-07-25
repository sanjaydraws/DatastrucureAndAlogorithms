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
    TreeNode* root = nullptr;
    unordered_map<int, int> inorderIndexMap;

    // Recursive helper function to build tree from postorder and inorder
    TreeNode* buildTreeHelper(vector<int>& postorder, vector<int>& inorder,
                              int inStart, int inEnd, int& postIndex) {
        // Base case
        if (inStart > inEnd) return nullptr;

        // Get current root value from postorder
        int rootVal = postorder[postIndex--];
        TreeNode* node = new TreeNode(rootVal);

        // If node has no children
        if (inStart == inEnd) return node;

        // Find index of root in inorder
        int inIndex = inorderIndexMap[rootVal];

        // Build right first (postorder → left, right, root)
        node->right = buildTreeHelper(postorder, inorder, inIndex + 1, inEnd, postIndex);
        node->left = buildTreeHelper(postorder, inorder, inStart, inIndex - 1, postIndex);

        return node;
    }

public:
    // Builds tree from postorder and inorder traversals
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inorderIndexMap.clear();
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;
        root = buildTreeHelper(postorder, inorder, 0, inorder.size() - 1, postIndex);
        return root;
    }

    // Level Order Traversal (each level in new line)
    void printLevelOrderByMarker() {
        if (!root) return;

        cout << "Level Order Traversal:\n";
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);  // End of level marker

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                cout << endl;
                if (!q.empty()) q.push(nullptr);
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
    vector<int> inorder   = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    BinaryTree bt;
    bt.buildTree(inorder, postorder);        // Build the tree
    bt.printLevelOrderByMarker();            // Print level order

    return 0;
}
