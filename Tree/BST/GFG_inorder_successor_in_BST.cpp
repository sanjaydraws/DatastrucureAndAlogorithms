//https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1
// Inorder Successor in BST

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
//GFG
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        Node* succ = nullptr;
        while(root){
          if(x->data < root->data){
            succ = root;
            root = root->left;
         }else{
             root = root->right;
         }
       }
       return succ ? succ->data : -1;
    }

*/
// -----------------------------
//  1. Iterative Approach (Using BST Property)
// T.C = O(h), S.C = O(1)
TreeNode* inorderSuccessorIterative(TreeNode* root, TreeNode* p) {
    TreeNode* successor = nullptr;
    while (root) {
        if (p->val < root->val) {
            successor = root;  // potential successor found
            root = root->left; // try for smaller one on left
        } else {
            root = root->right; // move right to find larger value
        }
    }
    return successor;
}

// -----------------------------
//  2. Recursive Approach (Using BST Property)
// T.C = O(h), S.C = O(h) due to recursion stack
TreeNode* inorderSuccessorRecursive(TreeNode* root, TreeNode* p) {
    if (!root) return nullptr;

    if (p->val >= root->val) {
        // successor must lie in right subtree
        return inorderSuccessorRecursive(root->right, p);
    } else {
        // potential successor, try finding smaller one in left
        TreeNode* left = inorderSuccessorRecursive(root->left, p);
        return left ? left : root;
    }
}

// -----------------------------
// 3. Inorder Traversal Approach (For any Binary Tree)
// T.C = O(n), S.C = O(n)
TreeNode* inorderSuccessorInorderTraversal(TreeNode* root, TreeNode* p) {
    TreeNode* successor = nullptr;
    bool found = false;

    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (!node || successor) return;
        inorder(node->left);
        if (found && !successor) successor = node; // first node after p
        if (node == p) found = true;               // found p
        inorder(node->right);
    };

    inorder(root);
    return successor;
}

// -----------------------------
//  4. Leftmost Node in Right Subtree
// T.C = O(h), S.C = O(1)
TreeNode* getRightSubtreeLeftmost(TreeNode* p) {
    TreeNode* curr = p->right;
    if (!curr) return nullptr;
    while (curr->left) {
        curr = curr->left;
    }
    return curr;
}


int main() {
    /*
            20
           /  \
         10    30
             /   \
           25     35
    */
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    TreeNode* p = root->left; // p = 10

    TreeNode* ans1 = inorderSuccessorIterative(root, p);
    TreeNode* ans2 = inorderSuccessorRecursive(root, p);
    TreeNode* ans3 = inorderSuccessorInorderTraversal(root, p);
    TreeNode* ans4 = getRightSubtreeLeftmost(p); // works only if p->right exists

    cout << "Iterative BST Property Successor: " << (ans1 ? ans1->val : -1) << endl;
    cout << "Recursive BST Property Successor: " << (ans2 ? ans2->val : -1) << endl;
    cout << "Inorder Traversal Successor: " << (ans3 ? ans3->val : -1) << endl;
    cout << "Right Subtree Leftmost (only if right exists): " << (ans4 ? ans4->val : -1) << endl;

    return 0;
}
