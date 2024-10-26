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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* pr;
        int levelSize = 1;
        int leftV = root->val;
        while (levelSize > 0) {
            for (int i=0; i < levelSize; ++i) {
                pr = que.front();
                que.pop();
                if (i==0) leftV = pr->val;
                if (pr->left) que.push(pr->left);
                if (pr->right) que.push(pr->right);
            }
            levelSize = que.size();
        }
        return leftV;
    }
};