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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {""};
        vector<string> result;
        stack<TreeNode*> st;
        stack<string> st_res;
        st.push(root);
        TreeNode* pnode;
        string path = to_string(root->val);
        st_res.push(path);
        while (!st.empty()) {
            pnode = st.top();
            st.pop();
            path = st_res.top();
            st_res.pop();
            if (!pnode->left && !pnode->right) {
                result.push_back(path);
            } else {
                if (pnode->right) {
                    st.push(pnode->right);
                    st_res.push(path + "->" + to_string(pnode->right->val));
                }
                if (pnode->left) {
                    st.push(pnode->left);
                    st_res.push(path + "->" + to_string(pnode->left->val));
                }
            }

        }

        return result;
    }
};