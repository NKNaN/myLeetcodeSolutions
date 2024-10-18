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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root && subRoot) return false;
        if (root && !subRoot) return false;
        if (root->val != subRoot->val) return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
        return isSame(root, subRoot) | isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
    }
    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a && b) return false;
        if (a && !b) return false;
        if (a->val != b->val) return false;
        return true & isSame(a->left, b->left) & isSame(a->right, b->right);
    }
};