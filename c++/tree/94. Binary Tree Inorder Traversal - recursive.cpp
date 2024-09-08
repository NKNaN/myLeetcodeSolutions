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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(nodes, root);
        return nodes;
    }
    void inorder(vector<int>& result, TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) inorder(result, root->left);
        result.push_back(root->val);
        if (root->right) inorder(result, root->right);
    }
};