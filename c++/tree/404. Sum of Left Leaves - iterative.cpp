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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        TreeNode* pr;
        stack<TreeNode*> st;
        st.push(root);
        int sum = 0;
        while (!st.empty()) {
            pr = st.top();
            st.pop();
            if (pr->left) st.push(pr->left);
            if (pr->right) st.push(pr->right);
            if (pr->left && !pr->left->left && !pr->left->right) {
                sum += pr->left->val;
            }
        }
        return sum;
    }
};