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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* pr = root;
        traversal_swap(pr);
        return root;
    }
    void traversal_swap(TreeNode* pr) {
        if (pr) {
            swapChilds(pr);
            if (pr->left) traversal_swap(pr->left);
            if (pr->right) traversal_swap(pr->right);
        }
    }
    void swapChilds(TreeNode* node) {
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
};