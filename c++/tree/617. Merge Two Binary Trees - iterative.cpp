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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        queue<TreeNode*> que_in;
        que_in.push(root1);
        que_in.push(root2);
        int levelSize_in = 2;
        queue<TreeNode*> que_out;
        TreeNode* root = new TreeNode(root1->val + root2->val);
        que_out.push(root);
        int levelSize_out = 1;
        TreeNode* pr1; 
        TreeNode* pr2;
        TreeNode* node;
        while (levelSize_in > 0 && levelSize_out > 0) {
            for (; levelSize_in>0; levelSize_in -= 2) {
                pr1 = que_in.front();
                que_in.pop();
                pr2 = que_in.front();
                que_in.pop();
                node = que_out.front();
                que_out.pop();
                if (node && pr1 && pr2) {
                    if (!pr1->left && !pr2->left) node->left = nullptr;
                    if (!pr1->left) node->left = pr2->left;
                    if (!pr2->left) node->left = pr1->left;
                    if (pr1->left && pr2->left) {
                        node->left = new TreeNode(pr1->left->val + pr2->left->val);
                    }
                    if (!pr1->right && !pr2->right) node->right = nullptr;
                    if (!pr1->right) node->right = pr2->right;
                    if (!pr2->right) node->right = pr1->right;
                    if (pr1->right && pr2->right) {
                        node->right = new TreeNode(pr1->right->val + pr2->right->val);
                    }

                    que_in.push(pr1->left);
                    que_in.push(pr2->left);
                    que_out.push(node->left);
                    que_in.push(pr1->right);
                    que_in.push(pr2->right);
                    que_out.push(node->right);
                }
            }
            levelSize_in = que_in.size();
        }
        return root;
    }
};