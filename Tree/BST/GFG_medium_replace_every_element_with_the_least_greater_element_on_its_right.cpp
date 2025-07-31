// Replace every element with the least greater element on its right
// https://www.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1

class Solution {
  public:
    // BST Node definition
    struct Node {
        int val;
        Node* left, *right;
        Node(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    // Insert into BST and track the successor
    Node* insert(Node* root, int key, int &successor) {
        // If current node is null, create a new one
        if (!root) return new Node(key);

        // If key is smaller, root can be successor
        if (key < root->val) {
            successor = root->val;
            root->left = insert(root->left, key, successor);
        } 
        // Otherwise go to right (larger values)
        else {
            root->right = insert(root->right, key, successor);
        }
        return root;
    }

    // Main function to find least greater element on right
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> res(n);          // Output array
        Node* root = nullptr;        // BST root

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            int successor = -1;      // Default value
            root = insert(root, arr[i], successor);  // Insert and find successor
            res[i] = successor;
        }
        return res;
    }
};


// Time Complexity:
// Insertion in BST: O(h) where h is height of BST
// In worst case (unbalanced), h = O(n)
// So total time: O(n^2) in worst case
// Average case (balanced BST): O(n log n)

// Space Complexity:
// O(n) for BST nodes
// O(n) extra for result array => Overall: O(n)
