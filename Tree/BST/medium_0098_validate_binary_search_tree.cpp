#include <iostream>
#include <climits>
using namespace std;

// Basic structure of a Tree Node
class TreeNode {
public:
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  long prev = LONG_MIN; // Used in Inorder approach to track last value

public:

  //  Approach 1: Recursive Top-Down Min/Max Bounds
  /*
    Approach:
    - For each node, we pass down the range it must lie in.
    - Left child must be in (min, node->val)
    - Right child must be in (node->val, max)
    - If any node violates, return false.
    
    Time: O(N) - visit each node once
    Space: O(H) - recursion stack (H = height of tree)
  */
  bool isValidBST_MinMax(TreeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
  }

  bool validate(TreeNode* node, long minVal, long maxVal) {
    if (!node) return true;

    // Node's value must lie within (minVal, maxVal)
    if (node->val <= minVal || node->val >= maxVal)
      return false;

    // Validate left and right with updated ranges
    return validate(node->left, minVal, node->val) &&
           validate(node->right, node->val, maxVal);
  }

  //  Approach 2: Inorder Traversal Check
  /*
    Approach:
    - Do inorder traversal and make sure the values are strictly increasing.
    - Track previous node value using a variable.
    - If at any point current node <= prev → not BST.

    Time: O(N) - visit all nodes once
    Space: O(H) - recursion stack (H = height of tree)
  */
  bool isValidBST_Inorder(TreeNode* root) {
    prev = LONG_MIN; // Reset before use
    return inorder(root);
  }

  bool inorder(TreeNode* node) {
    if (!node) return true;

    // Traverse left subtree
    if (!inorder(node->left)) return false;

    // Compare current node with previous value
    if (node->val <= prev) return false;
    prev = node->val;

    // Traverse right subtree
    return inorder(node->right);
  }
};
