// Diagonal Tree Traversal
//https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        if(!root) return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* temp = q.front(); q.pop();

            while(temp) {
                ans.push_back(temp->data);

                // Push left child to queue for next diagonal
                if(temp->left) q.push(temp->left);

                // Move to right in the same diagonal
                temp = temp->right;
            }
        }

        return ans;
    }
};
//  Time Complexity: O(N) (each node is visited exactly once)
//  Space Complexity: O(N) (queue + result stores up to N nodes)