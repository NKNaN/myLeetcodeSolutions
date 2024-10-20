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
    vector<string> result;

    void getPath(TreeNode* node, string path) {
        if (!node) return;
        if (!node->left && !node->right) {
            path = path + std::to_string(node->val);
            result.push_back(path);
        } else {
            path = path + std::to_string(node->val) + "->";
            getPath(node->left, path);
            getPath(node->right, path);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {""};
        getPath(root, "");
        return result;
    }
};