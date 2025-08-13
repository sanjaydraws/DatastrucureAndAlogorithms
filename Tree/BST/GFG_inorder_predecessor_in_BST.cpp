//Inorder Predecessor in BST
/*
Structure of Node:
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    //  Approach 1: Node has a left subtree — go to left, then max right
    // T.C: O(h), S.C: O(1)
    Node* findPredecessorUsingLeft(Node* x) {
        if (!x || !x->left) return nullptr;

        Node* pred = x->left;
        while (pred->right) {
            pred = pred->right;
        }
        return pred;
    }

    //  Approach 2: Node doesn't have left subtree — start from root
    // Find the largest value less than x->data
    // T.C: O(h), S.C: O(1)
    Node* findPredecessorFromRoot(Node* root, Node* x) {
        Node* pred = nullptr;

        while (root) {
            if (x->data <= root->data) {
                // Current root is >= x, can't be predecessor — go left
                root = root->left;
            } else {
                // root->data < x->data — valid pred, but try right for larger
                pred = root;
                root = root->right;
            }
        }
        return pred;
    }

    //  Combined function to get inorder predecessor of node x
    Node* inorderPredecessor(Node* root, Node* x) {
        // Case 1: Left subtree present
        Node* leftPred = findPredecessorUsingLeft(x);
        if (leftPred) return leftPred;

        // Case 2: No left subtree — use root path
        return findPredecessorFromRoot(root, x);
    }
};
