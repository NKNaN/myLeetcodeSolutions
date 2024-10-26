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
    vector<vector<int>> result;
    void traversal(TreeNode* node, vector<int>& path, int count) {
        if (node->left) {
            path.push_back(node->left->val);
            count -= node->left->val;
            traversal(node->left, path, count);
            path.pop_back();
            count += node->left->val;
        }
        if (node->right) {
            path.push_back(node->right->val);
            count -= node->right->val;
            traversal(node->right, path, count);
            path.pop_back();
            count += node->right->val;
        }
        if (!node->left && !node->right) {
            if (count == 0) result.push_back(path);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<int> path = {root->val};
        traversal(root, path, targetSum - root->val);
        return result;
    }
};