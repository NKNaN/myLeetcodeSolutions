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
        swap(pr->left, pr->right);
        if (pr->right) st.push(pr->right);
        if (pr->left) st.push(pr->left);
        while (!st.empty()) {
            pr = st.top();
            st.pop();
            swap(pr->left, pr->right);
            if (pr->right) st.push(pr->right);
            if (pr->left) st.push(pr->left);
        }
        return root;
    }
};