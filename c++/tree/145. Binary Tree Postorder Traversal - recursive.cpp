/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(nodes, root);
        return nodes;
    }
    void postorder(vector<int>& result, TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) postorder(result, root->left);
        if (root->right) postorder(result, root->right);
        result.push_back(root->val);
    }
};