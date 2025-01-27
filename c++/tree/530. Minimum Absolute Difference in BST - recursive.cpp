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
    int getMaxSubtreeVal(TreeNode* node) {
        while (node->right) {
            node = node->right;
        }
        return node->val;
    }
    int getMinSubtreeVal(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node->val;
    }
    int getSubtreeDiff(TreeNode* root) {
        int leftdiff = INT_MAX;
        int rightdiff = INT_MAX;
        if (root->left) {
            leftdiff = abs(root->val - getMaxSubtreeVal(root->left));
        }
        if (root->right) {
            rightdiff = abs(root->val - getMinSubtreeVal(root->right));
        }
        return min(leftdiff, rightdiff);
    }
    int getMinimumDifference(TreeNode* root) {
        if ((root->left && !root->right && !root->left->left && !root->left->right) ||
            (root->right && !root->left && !root->right->left && !root->right->right) ||
            (root->left && root->right && !root->left->left && !root->left->right 
            && !root->right->left && !root->right->right)) return getSubtreeDiff(root);
        int leftmin = getSubtreeDiff(root);
        int rightmin = getSubtreeDiff(root);
        int tmp_min = min(leftmin, rightmin);
        int leftmindiff = INT_MAX;
        int rightmindiff = INT_MAX;
        if (root->left) leftmindiff = getMinimumDifference(root->left);
        if (root->right) rightmindiff = getMinimumDifference(root->right);
        return min(tmp_min, min(leftmindiff, rightmindiff));
    }
};