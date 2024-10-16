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
        stack<TreeNode*> st;
        if (pr->right) st.push(pr->right);
        st.push(pr);
        st.push(nullptr);
        if (pr->left) st.push(pr->left);
        while (!st.empty()) {
            pr = st.top();
            st.pop();
            if (pr) {
                if (pr->right) st.push(pr->right);
                st.push(pr);
                st.push(nullptr);
                if (pr->left) st.push(pr->left);
            } else {
                pr = st.top();
                st.pop();
                swap(pr->left, pr->right);
            }
        }
        return root;
    }
};