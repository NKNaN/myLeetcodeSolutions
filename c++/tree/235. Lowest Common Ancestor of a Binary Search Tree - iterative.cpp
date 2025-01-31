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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        if (!root) return root;
        que.push(root);
        int levelSize = 1;
        TreeNode* cur;
        int lo = min(p->val, q->val);
        int hi = max(p->val, q->val);
        while(levelSize > 0) {
            for (int i=0; i<levelSize; ++i) {
                cur = que.front();
                que.pop();
                if (cur->val >= lo && cur->val <= hi) return cur;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            levelSize = que.size();
        }
        return nullptr;
    }
};