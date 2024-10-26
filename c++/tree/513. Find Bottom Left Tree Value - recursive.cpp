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
    int maxdepth = 0;
    int result;
    void getDepth(TreeNode* node, int depth) {
        if (depth > maxdepth) {
            maxdepth = depth;
            if (!node->left && !node->right) {
                result = node->val;
            }
        }
        if (node->left) {
            ++depth;
            getDepth(node->left, depth);
            --depth;
        }
        if (node->right) {
            ++depth;
            getDepth(node->right, depth);
            --depth;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        getDepth(root, 1);
        return result;
    }
};