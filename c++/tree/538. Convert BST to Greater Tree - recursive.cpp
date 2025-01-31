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
private:
    int amount;
public:
    void traversal(TreeNode* root) {
        if (!root) return;
        traversal(root->right);
        root->val += amount;
        amount = root->val;
        traversal(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        amount = 0;
        traversal(root);
        return root;
    }
};