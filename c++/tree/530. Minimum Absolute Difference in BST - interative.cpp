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
    int getMinimumDifference(TreeNode* root) {
        TreeNode* pr = root;
        int minDiff = 1e5;
        stack<TreeNode*> st;
        st.push(pr);
        int prev = 1e5;
        while(!st.empty()) {
            pr = st.top();
            if (pr) {
                st.pop();
                if (pr->right) st.push(pr->right);
                st.push(pr);
                st.push(nullptr);
                if (pr->left) st.push(pr->left);
            } else {
                st.pop(); // pop null
                pr = st.top();
                st.pop();
                // cout<<pr->val<<endl;
                if (pr->val - prev < minDiff) minDiff = abs(pr->val - prev);
                prev = pr->val;
            }
        }
        return minDiff;
    }
};