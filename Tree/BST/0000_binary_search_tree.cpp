#include<iostream>
#include<queue>
using namespace std;

// Binary Search Tree Node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

// BST Class
class BST {
public:
    TreeNode* root;

    BST() {
        root = nullptr;
    }

    // INSERT FUNCTION (recursive)
    // T.C: O(H) | S.C: O(H) where H = height of tree
    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);

        if (val < node->val)
            node->left = insert(node->left, val);
        else if (val > node->val)
            node->right = insert(node->right, val);

        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    // INORDER TRAVERSAL: Left → Root → Right
    // T.C: O(n) | S.C: O(H)
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    // SEARCH FUNCTION
    // T.C: O(H) | S.C: O(H)
    bool search(TreeNode* node, int key) {
        if (!node) return false;

        if (node->val == key) return true;
        else if (key < node->val)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // FIND MINIMUM VALUE NODE (leftmost node)
    // T.C: O(H) | S.C: O(1)
    TreeNode* findMin(TreeNode* node) {
        if (!node) return nullptr;
        while (node->left) node = node->left;
        return node;
    }

    // FIND MAXIMUM VALUE NODE (rightmost node)
    // T.C: O(H) | S.C: O(1)
    TreeNode* findMax(TreeNode* node) {
        if (!node) return nullptr;
        while (node->right) node = node->right;
        return node;
    }

    // DELETE FUNCTION
    // T.C: O(H) | S.C: O(H)
    TreeNode* deleteNode(TreeNode* node, int key) {
        if (!node) return nullptr;

        if (key < node->val) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->val) {
            node->right = deleteNode(node->right, key);
        } else {
            // CASE 1: Node has no children
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }

            // CASE 2: Node has one child
            if (!node->left || !node->right) {
                TreeNode* child = node->left ? node->left : node->right;
                delete node;
                return child;
            }

            // CASE 3: Node has two children
            TreeNode* successor = findMin(node->right);
            node->val = successor->val;
            node->right = deleteNode(node->right, successor->val);
        }

        return node;
    }
    TreeNode* bstFromInorderHelper(int inorder[], int s, int e){
        if(s > e) return nullptr;
        int mid = (s + e) / 2;
        int element = inorder[mid];
        TreeNode* root = new TreeNode(element);
        root->left = bstFromInorderHelper(inorder, s, mid -1);
        root->right = bstFromInorderHelper(inorder, mid + 1, e);
        return  root;
    }
    void bstFromInorder(int inorder[], int s, int e){
         root = bstFromInorderHelper(inorder, s, e);
    }

    // Print level order traversal (line by line using null marker)
    void levelOrderTraversal(TreeNode* root){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr); // null marker for new level
        while(!q.empty()){
          TreeNode* node = q.front();
          q.pop();
          if(node == nullptr){
            cout<<endl;
            if(!q.empty()) q.push(nullptr);
          }else{
            cout<<node->val<<" ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
          }
        }
    }
};

int main() {
    BST tree;

    // Insert nodes
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "Inorder: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Search 115: " << tree.search(tree.root, 115) << endl;

    cout << "Find Min: " << tree.findMin(tree.root)->val << endl;
    cout << "Find Max: " << tree.findMax(tree.root)->val << endl;

    // Delete a node
    tree.root = tree.deleteNode(tree.root, 10);

    cout << "Inorder after delete: ";
    tree.inorder(tree.root);
    cout << endl;

    int inorder[] = {1,2,3,4,5,6,7};
    tree.bstFromInorder(inorder,0,6);
    cout << endl;
    cout<<"inorder of bst from inorder:\n";
    tree.levelOrderTraversal(tree.root);

    return 0;
}
