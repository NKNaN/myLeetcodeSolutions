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
   TreeNode* upper;
   TreeNode* lower;
public:
    bool isValidBST(TreeNode* root) {
        if (!root->right && !root->left) return true;
        bool isValid = true;
        if (root->left && root->left->val >= root->val) isValid = false;
        if (lower && root->left && lower->val >= root->left->val) isValid = false;
        if (root->right &&  root->val >= root->right->val) isValid = false;
        if (upper && root->right && root->right->val >= upper->val) isValid = false;
        bool isValidLeft = true;
        if (root->left) {
            TreeNode* tmp_u = upper;
            upper = root;
            isValidLeft = isValidBST(root->left);
            upper = tmp_u;
        }
        bool isValidRight = true;
        if (root->right) {
            TreeNode* tmp_l = lower;
            lower = root;
            isValidRight = isValidBST(root->right);
            lower = tmp_l;
        }
        return isValid && isValidLeft && isValidRight;
    }
};