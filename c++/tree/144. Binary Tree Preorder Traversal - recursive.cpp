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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(nodes, root);
        return nodes;
    }
    void preorder(vector<int>& result, TreeNode* root) {
        if (root == nullptr) return;
        result.push_back(root->val);
        if (root->left) preorder(result, root->left);
        if (root->right) preorder(result, root->right);
    }
};