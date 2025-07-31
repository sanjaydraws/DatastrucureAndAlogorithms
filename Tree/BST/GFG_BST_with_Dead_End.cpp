// BST with Dead End
// https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

#include <bits/stdc++.h>
using namespace std;

// Tree Node definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

//////////////////////////////////////////////////////////////
// APPROACH 1: Recursive Min-Max Range Method
//  Idea:
// For each node, maintain a range [minVal, maxVal] of valid values
// If min == max at any point, no node can be inserted here ⇒ Dead end
// 
//  T.C: O(n)  — visiting each node once
//  S.C: O(h) — recursion stack height (h = height of BST)

bool isDeadEndRecursive(TreeNode* root, int minVal, int maxVal) {
    if (!root) return false;

    // If no room to insert any node ⇒ dead end
    if (minVal == maxVal) return true;

    // Check left and right subtrees with updated ranges
    return isDeadEndRecursive(root->left, minVal, root->val - 1) ||
           isDeadEndRecursive(root->right, root->val + 1, maxVal);
}

bool isDeadEnd_Approach1(TreeNode* root) {
    return isDeadEndRecursive(root, 1, INT_MAX);  // BST nodes ≥ 1
}

//////////////////////////////////////////////////////////////
// APPROACH 2: Set-Based Method using Hashing
//  Idea:
// 1. Store all node values and all leaf values in two sets.
// 2. For each leaf, check if (leaf-1) and (leaf+1) are both present in node set.
//    If yes → no new node can be inserted ⇒ dead end.
//  T.C: O(n) — single DFS + loop on leaves
//  S.C: O(n) — storing all nodes and leaves
//////////////////////////////////////////////////////////////

void collect(TreeNode* root, unordered_set<int>& nodes, unordered_set<int>& leaves) {
    if (!root) return;

    nodes.insert(root->val);

    // If leaf node, store it separately
    if (!root->left && !root->right)
        leaves.insert(root->val);

    collect(root->left, nodes, leaves);
    collect(root->right, nodes, leaves);
}

bool isDeadEnd_Approach2(TreeNode* root) {
    unordered_set<int> nodes, leaves;
    nodes.insert(0);  // Add 0 to handle leaf = 1 edge case

    collect(root, nodes, leaves);

    // Check each leaf
    for (int leaf : leaves) {
        if (nodes.count(leaf - 1) && nodes.count(leaf + 1)) {
            return true;
        }
    }

    return false;
}




//////////////////////////////////////////////////////////////
//  APPROACH 3: Using HashMap to track nodes & leaves
// -----------------------------------------------------------
// IDEA:
// - Store all nodes in a hashmap as node[val] = 1
// - Store all leaf nodes in another hashmap
// - For each leaf, check if (leaf - 1) and (leaf + 1) exist in map
//   => if yes ⇒ no insertion possible ⇒ dead end
//
//  Time Complexity: O(n)
//  Space Complexity: O(n)
// Uses two hashmaps: one for all nodes, one for leaf nodes

void dfs(TreeNode* root, unordered_map<int, int>& nodeMap, unordered_map<int, int>& leafMap) {
    if (!root) return;

    nodeMap[root->val]++;

    if (!root->left && !root->right) {
        leafMap[root->val]++;
    }

    dfs(root->left, nodeMap, leafMap);
    dfs(root->right, nodeMap, leafMap);
}

bool isDeadEnd_Approach3(TreeNode* root) {
    unordered_map<int, int> nodeMap, leafMap;

    nodeMap[0] = 1;  // To handle leaf=1 edge case

    dfs(root, nodeMap, leafMap);

    for (auto& it : leafMap) {
        int leaf = it.first;
        if (nodeMap.count(leaf - 1) && nodeMap.count(leaf + 1)) {
            return true;
        }
    }

    return false;
}
