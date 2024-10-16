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
        if (root == nullptr) return {};
        vector<int> nodes;
        stack<TreeNode*> st;
        TreeNode* pr = root;
        if (pr->right) st.push(pr->right);
        if (pr->left) st.push(pr->left);
        if (pr) {
            st.push(pr);
            st.push(nullptr);
        }
        while (!st.empty()) {
            pr = st.top();
            st.pop();
            if (pr == nullptr) {
                pr = st.top();
                st.pop();
                nodes.push_back(pr->val);
            } else {
                if (pr->right) st.push(pr->right);
                if (pr->left) st.push(pr->left);
                st.push(pr);
                st.push(nullptr);
            }
        }

        return nodes;
    }
};