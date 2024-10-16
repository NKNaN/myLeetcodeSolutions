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
        if (!root) return root;
        TreeNode* pr = root;
        queue<TreeNode*> que;
        que.push(pr);
        int levelSize = 1;
        while (levelSize > 0) {
            for (int i=0; i<levelSize; ++i) {
                pr = que.front();
                que.pop();
                swap(pr->left, pr->right);
                if (pr->left) que.push(pr->left);
                if (pr->right) que.push(pr->right);
            }
            levelSize = que.size();
        }
        return root;
    }
};