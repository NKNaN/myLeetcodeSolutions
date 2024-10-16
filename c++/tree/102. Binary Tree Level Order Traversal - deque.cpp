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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> nodes;
        deque<TreeNode*> dq;
        TreeNode* pr = root;
        dq.push_back(pr);
        int levelSize = 1;
        while (levelSize != 0) {
            vector<int> level;
            for (; levelSize>0; --levelSize) {
                pr = dq.front();
                dq.pop_front();
                level.push_back(pr->val);
                if (pr->left) dq.push_back(pr->left);
                if (pr->right) dq.push_back(pr->right);
            }
            nodes.push_back(level);
            levelSize = dq.size();
        }
        return nodes;
    }
};