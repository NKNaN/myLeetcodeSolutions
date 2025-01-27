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
    TreeNode* prev;
    int n_mode;
    int n_cur;
    vector<int> result;
public:
    void traversal(TreeNode* cur) {
        if (!cur) return;
        if (cur->left) traversal(cur->left);
        if (prev != nullptr) {
            if (prev->val == cur->val) {
                ++n_cur;
            } else {
                n_cur = 1;
            }
        } else {
            ++n_mode;
            ++n_cur;
        }
        if (n_cur == n_mode) {
            result.push_back(cur->val);   
        } else if (n_cur > n_mode) {
            result.clear();
            result.push_back(cur->val);
            n_mode = n_cur; 
        }
        prev = cur;
        if (cur->right) traversal(cur->right);
    }

    vector<int> findMode(TreeNode* root) {
        n_mode = 0;
        n_cur = 0;
        traversal(root);
        return result;
    }
};