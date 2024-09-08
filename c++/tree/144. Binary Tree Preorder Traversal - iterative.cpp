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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> st;
        TreeNode* pr = root;
        if (pr) st.push(pr);
        while (!st.empty()) {
            pr = st.top();
            nodes.push_back(pr->val);
            st.pop();
            if (pr->right) st.push(pr->right);
            if (pr->left) st.push(pr->left);
        }

        return nodes;
    }
};