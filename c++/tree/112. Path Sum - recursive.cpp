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
    bool result = false;
    void traversal(TreeNode* node, int targetSum) {
        if (!node->left && !node->right && node->val == targetSum) {
            result = true;
        }
        if (node->left) {
            targetSum -= node->val;
            traversal(node->left, targetSum);
            targetSum += node->val;
        }
        if (node->right) {
            targetSum -= node->val;
            traversal(node->right, targetSum);
            targetSum += node->val;
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        traversal(root, targetSum);
        return result;
    }
};