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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> nodes;
        queue<TreeNode*> que;
        que.push(root);
        int levelSize = 1;
        TreeNode* pr;
        while (levelSize > 0) {
            for (; levelSize>0; --levelSize) {
                pr = que.front();
                que.pop();
                if (levelSize == 1) nodes.push_back(pr->val);
                if (pr->left) que.push(pr->left);
                if (pr->right) que.push(pr->right);
            }
            levelSize = que.size();
        }
        return nodes;
    }
};