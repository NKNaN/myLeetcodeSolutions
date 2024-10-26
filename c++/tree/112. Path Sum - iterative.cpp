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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        stack<TreeNode*> st;
        st.push(root);
        stack<int> st_ps;
        st_ps.push(root->val);
        TreeNode* pr;
        int tmpv;
        while (!st.empty()) {
            pr = st.top(); st.pop();
            tmpv = st_ps.top(); st_ps.pop();
            if (!pr->left && !pr->right && tmpv == targetSum) {
                return true;
            }
            if (pr->right) {
                st.push(pr->right);
                st_ps.push(tmpv + pr->right->val);
            }
            if (pr->left) {
                st.push(pr->left);
                st_ps.push(tmpv + pr->left->val);
            }
        }
        return false;
    }
};