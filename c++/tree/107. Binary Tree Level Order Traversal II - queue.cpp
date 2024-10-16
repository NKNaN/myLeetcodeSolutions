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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> que;
        TreeNode* pr = root;
        que.push(pr);
        int levelSize = 1;
        vector<vector<int>> nodes;
        while (levelSize>0) {
            vector<int> level;
            for (; levelSize>0; --levelSize) {
                pr = que.front();
                que.pop();
                level.push_back(pr->val);
                if (pr->left) que.push(pr->left);
                if (pr->right) que.push(pr->right);
            }
            nodes.push_back(level);
            levelSize = que.size();
        }
        reverse(nodes.begin(), nodes.end());
        return nodes;
    }
};