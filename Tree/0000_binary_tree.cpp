#include<iostream>
#include<queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data): val(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // Inorder: Left → Root → Right
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    // Preorder: Root → Left → Right
    void preorder(TreeNode* node) {
        if (!node) return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Postorder: Left → Right → Root
    void postorder(TreeNode* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->val << " ";
    }

    // Build tree recursively using -1 as null marker
    TreeNode* buildTree() {
        int data;
        cout << "Enter Data: ";
        cin >> data;
        if (data == -1) return nullptr;
        TreeNode* node = new TreeNode(data);
        cout << "Enter left child of " << data << ": ";
        node->left = buildTree();
        cout << "Enter right child of " << data << ": ";
        node->right = buildTree();
        return node;
    }

public:
    BinaryTree(): root(nullptr) {}

    // Build binary tree from user input
    void createTree() {
        cout << "Build binary tree\n";
        root = buildTree();
    }

    // Inorder Traversal
    void printInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    // Preorder Traversal
    void printPreorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    // Postorder Traversal
    void printPostorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    // Level Order Traversal (single line)
    void printLevelOrder() {
        if (!root) return;
        cout << "Level Order Traversal : ";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->val << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }

    // Level Order Traversal (line by line using nullptr marker)
    void printLevelOrderByMarker() {
        if (!root) return;
        cout << "Level Order Traversal :\n";
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);  // Marker for end of level

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current == nullptr) {
                cout << endl;
                if (!q.empty()) q.push(nullptr);
            } else {
                cout << current->val << " ";
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
    }
};

int main() {
    BinaryTree tree;
    tree.createTree();
    tree.printInorder();           // T.C: O(n), S.C: O(h)
    tree.printPreorder();          // T.C: O(n), S.C: O(h) // h = tree height (recursive stack)
    tree.printPostorder();         // T.C: O(n), S.C: O(h)
    tree.printLevelOrder();        // T.C: O(n), S.C: O(w) //w = max width of tree (queue)
    tree.printLevelOrderByMarker();// T.C: O(n), S.C: O(w)
    return 0;
}
