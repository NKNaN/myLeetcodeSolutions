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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int levelSize = 1;
        TreeNode* pr;
        while (levelSize>0) {
            vector<int> level(levelSize);
            vector<int> level_reverse(levelSize);
            for (int i=0; i<levelSize; ++i) {
                pr = que.front();
                que.pop();
                int val = (pr ? pr->val : -101);
                level[i] = val;
                level_reverse[levelSize - 1 - i] = val;
                if (pr) {
                    que.push(pr->left);
                    que.push(pr->right);
                }
            }
            for (int i=0; i<levelSize; ++i) {
                if (level[i] != level_reverse[i]) return false;
            }
            levelSize = que.size();
            if (levelSize % 2 == 1) return false;
        }
        return true;
    }
};