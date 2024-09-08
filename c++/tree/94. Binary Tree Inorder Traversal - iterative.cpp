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
        // if (root == nullptr) return {};
        vector<int> nodes;
        stack<TreeNode*> st;
        TreeNode* pr = root;
        // if (pr) st.push(pr);
        while (pr != nullptr || !st.empty()) {
            if (pr) {
                st.push(pr);
                pr = pr->left;
            } else { // pr is null -> stack top node is root, so should be popped first
                pr = st.top();
                st.pop(); // delete pr in stack
                nodes.push_back(pr->val);
                pr = pr->right; // move to root->right
            }
        }

        return nodes;
    }
};