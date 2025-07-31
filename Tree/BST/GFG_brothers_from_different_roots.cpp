//https://www.geeksforgeeks.org/problems/brothers-from-different-root/1
// Brothers From Different Roots
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// ---------- 1. Brute Force: Inorder + Set lookup ----------
void inorder(TreeNode* root, unordered_set<int>& s) {
    if (!root) return;
    inorder(root->left, s);
    s.insert(root->val);
    inorder(root->right, s);
}

int countPairsBrute(TreeNode* root1, TreeNode* root2, int x) {
    unordered_set<int> s;
    inorder(root1, s);  // Store BST1 values

    // Traverse BST2 and check (x - val) in set
    int count = 0;
    stack<TreeNode*> stk;
    TreeNode* curr = root2;
    while (curr || !stk.empty()) {
        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top(); stk.pop();
        if (s.count(x - curr->val)) count++;
        curr = curr->right;
    }
    return count;
}
// T.C: O(n + m), S.C: O(n) for storing values from first tree

// ---------- 2. Inorder + Binary Search on Tree2 ----------
void getInorder(TreeNode* root, vector<int>& inorderList) {
    if (!root) return;
    getInorder(root->left, inorderList);
    inorderList.push_back(root->val);
    getInorder(root->right, inorderList);
}

bool search(TreeNode* root, int key) {
    if (!root) return false;
    if (root->val == key) return true;
    if (key < root->val) return search(root->left, key);
    return search(root->right, key);
}

int countPairsBinarySearch(TreeNode* root1, TreeNode* root2, int x) {
    vector<int> v;
    getInorder(root1, v);  // Store all values of root1

    int count = 0;
    for (int val : v) {
        if (search(root2, x - val)) count++;
    }
    return count;
}
// T.C: O(n * log m), S.C: O(n) for inorder list

// ---------- 3. Most Optimal: Two Stacks (Inorder + Reverse Inorder) ----------
int countPairsTwoStacks(TreeNode* root1, TreeNode* root2, int x) {
    stack<TreeNode*> s1, s2;
    TreeNode* curr1 = root1;
    TreeNode* curr2 = root2;

    int count = 0;

    while (true) {
        // Push all left nodes of root1 (inorder)
        while (curr1) {
            s1.push(curr1);
            curr1 = curr1->left;
        }

        // Push all right nodes of root2 (reverse inorder)
        while (curr2) {
            s2.push(curr2);
            curr2 = curr2->right;
        }

        if (s1.empty() || s2.empty()) break;

        TreeNode* top1 = s1.top();
        TreeNode* top2 = s2.top();

        int sum = top1->val + top2->val;

        if (sum == x) {
            count++;
            s1.pop();
            s2.pop();
            curr1 = top1->right;
            curr2 = top2->left;
        } else if (sum < x) {
            s1.pop();
            curr1 = top1->right;
        } else {
            s2.pop();
            curr2 = top2->left;
        }
    }

    return count;
}
// T.C: O(n + m), S.C: O(h1 + h2) where h1, h2 = height of BSTs
