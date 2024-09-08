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
    vector<int> postorderTraversal(TreeNode* root) { //derived from preorder - iterative
        vector<int> nodes;
        stack<TreeNode*> st;
        TreeNode* pr = root;
        if (pr) st.push(root);
        while (!st.empty()) {
            pr = st.top();
            st.pop();
            nodes.push_back(pr->val);
            if (pr->left) st.push(pr->left); // switch order
            if (pr->right) st.push(pr->right); // switch order
        } // get root, right, left
        reverse(nodes.begin(), nodes.end()); // reverse nodes

        return nodes;
    }
};