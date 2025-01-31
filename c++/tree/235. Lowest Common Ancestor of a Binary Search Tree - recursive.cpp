/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* result;
    bool stop;
public:
    void traversal(TreeNode* cur, int lo, int hi) {
        if (!cur) return;
        if (!stop && lo <= cur->val && cur->val <= hi) {
            result = cur;
            stop = true;
        }
        if (cur->left) traversal(cur->left, lo, hi);
        if (cur->right) traversal(cur->right, lo, hi);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        stop = false;
        int lo = min(p->val, q->val);
        int hi = max(p->val, q->val);
        traversal(root, lo, hi);
        return result;
    }
};