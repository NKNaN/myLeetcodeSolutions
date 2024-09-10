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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> nodes;
        stack<TreeNode*> st;
        TreeNode* pr = root;
        st.push(pr);
        while (!st.empty()) {
            pr = st.top();
            st.pop();
            if (pr == nullptr) { // st.top is nullptr
                // cout<<"---:"<<st.top()->val<<endl;
                nodes.push_back(st.top()->val); // root node
                st.pop();
            } else {
                if (pr->right) st.push(pr->right);
                st.push(pr);
                st.push(nullptr); // mark before root
                if (pr->left) st.push(pr->left);
            }
        }

        return nodes;
    }
};