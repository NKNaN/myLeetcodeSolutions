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
    int result = 100001;
    void getDepths(TreeNode* node, int depth) {
        if (!node->left && !node->right) {
            result = (result < depth) ? result : depth;
        }
        if (node->left) {
            ++depth;
            getDepths(node->left, depth);
            --depth;
        }
        if (node->right) {
            ++depth;
            getDepths(node->right, depth);
            --depth;
        }
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        getDepths(root, 1);
        return result;
    }
};