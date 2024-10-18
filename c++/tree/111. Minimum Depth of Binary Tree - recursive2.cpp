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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int leftMin = minDepth(root->left);
        int rightMin = minDepth(root->right);
        if (!root->left && root->right) return 1 + rightMin;
        if (root->left && !root->right) return 1 + leftMin;
        return 1 + min(leftMin, rightMin);
    }
};