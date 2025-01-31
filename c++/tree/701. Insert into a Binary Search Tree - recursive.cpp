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
    void traversal(TreeNode* cur, int val) {
        if (val > cur->val) {
            if (cur->right) {
                traversal(cur->right, val);
            } else {
                cur->right = new TreeNode(val);
            }
        } else {
            if (cur->left) {
                traversal(cur->left, val);
            } else {
                cur->left = new TreeNode(val);
            }
        }

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        traversal(root, val);
        return root;
    }
};