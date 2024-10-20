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
    bool balanced = true;
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        if (abs(left - right)>1) balanced = false;
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        getHeight(root);
        return balanced;
    }
};