//https://www.geeksforgeeks.org/problems/brothers-from-different-root/1
// Brothers From Different Roots
#include <bits/stdc++.h>
using namespace std;

// Basic TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// ---------- 1. Brute Force: Inorder traversal + HashSet lookup ----------

// Store all nodes from root1 into a set using inorder traversal
void inorder(TreeNode* root, unordered_set<int>& s) {
    if (!root) return;
    inorder(root->left, s);
    s.insert(root->val);
    inorder(root->right, s);
}

int countPairsBrute(TreeNode* root1, TreeNode* root2, int x) {
    unordered_set<int> s;

    // Step 1: Traverse root1 and store all values in a hash set
    inorder(root1, s);

    // Step 2: Inorder traversal of root2 using stack (iterative)
    int count = 0;
    stack<TreeNode*> stk;
    TreeNode* curr = root2;

    while (curr || !stk.empty()) {
        // Go to leftmost node
        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }

        // Visit the node
        curr = stk.top(); stk.pop();

        // Check if x - curr->val exists in the set (i.e., from root1)
        if (s.count(x - curr->val)) count++;

        // Move to right subtree
        curr = curr->right;
    }

    return count;
}
// T.C: O(n + m), S.C: O(n) for hash set

// ---------- 2. Inorder + Binary Search on second tree ----------

// Store inorder of root1 into vector
void getInorder(TreeNode* root, vector<int>& inorderList) {
    if (!root) return;
    getInorder(root->left, inorderList);
    inorderList.push_back(root->val);
    getInorder(root->right, inorderList);
}

// Standard BST search in root2
bool search(TreeNode* root, int key) {
    if (!root) return false;
    if (root->val == key) return true;
    if (key < root->val) return search(root->left, key);
    return search(root->right, key);
}

int countPairsBinarySearch(TreeNode* root1, TreeNode* root2, int x) {
    vector<int> v;

    // Step 1: Store inorder of root1 in vector
    getInorder(root1, v);

    // Step 2: For every val in root1, check if (x - val) exists in root2 using BST search
    int count = 0;
    for (int val : v) {
        if (search(root2, x - val)) count++;
    }

    return count;
}
// T.C: O(n * log m), S.C: O(n)

// ---------- 3. Most Optimal: Two Stacks (Inorder + Reverse Inorder) ----------

int countPairsTwoStacks(TreeNode* root1, TreeNode* root2, int x) {
    stack<TreeNode*> s1, s2;
    TreeNode* curr1 = root1;
    TreeNode* curr2 = root2;
    int count = 0;

    while (true) {
        // Push all left children from root1 for inorder traversal
        while (curr1) {
            s1.push(curr1);
            curr1 = curr1->left;
        }

        // Push all right children from root2 for reverse inorder traversal
        while (curr2) {
            s2.push(curr2);
            curr2 = curr2->right;
        }

        // If either stack is empty, traversal is complete
        if (s1.empty() || s2.empty()) break;

        TreeNode* top1 = s1.top();
        TreeNode* top2 = s2.top();

        int sum = top1->val + top2->val;

        // If pair found
        if (sum == x) {
            count++;
            s1.pop();
            s2.pop();

            // Move to next inorder (right of top1) and reverse inorder (left of top2)
            curr1 = top1->right;
            curr2 = top2->left;
        }
        else if (sum < x) {
            // Need a bigger value ⇒ Move inorder forward (right subtree of top1)
            s1.pop();
            curr1 = top1->right;
        }
        else {
            // Need a smaller value ⇒ Move reverse inorder forward (left subtree of top2)
            s2.pop();
            curr2 = top2->left;
        }
    }

    return count;
}
// T.C: O(n + m), S.C: O(h1 + h2), where h1, h2 are heights of the two trees
