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
    int getSum(TreeNode* parent, TreeNode* node) {
        if (!node) return 0;
        int leftSum = getSum(node, node->left);
        int rightSum = getSum(node, node->right);
        if (!node->left && !node->right && parent->left == node) {
            return node->val;
        } else if (!node->left && !node->right && parent->right == node) {
            return 0;
        } else {
            return leftSum + rightSum;
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return getSum(root, root);
    }
};