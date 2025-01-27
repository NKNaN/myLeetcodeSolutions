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
    TreeNode* buildTreeByIndex(vector<int>& inorder,
                               vector<int>& postorder,
                               int inorderLeft,
                               int postorderLeft,
                               int treeSize) {
        if (treeSize == 0) return nullptr;
        int rootV = postorder[postorderLeft + treeSize - 1];
        TreeNode* root = new TreeNode(rootV);
        if (treeSize == 1) return root;
        int idx = inorderLeft;
        for (; idx < inorderLeft + treeSize; ++idx)
            if (inorder[idx] == rootV)
                break;
        int leftTreeSize = idx - inorderLeft;
        int rightTreeSize = treeSize - leftTreeSize - 1;
        int inorderRight = idx + 1;
        int postorderRight = postorderLeft + leftTreeSize;
        root->left = buildTreeByIndex(inorder, postorder, inorderLeft, postorderLeft, leftTreeSize);
        root->right = buildTreeByIndex(inorder, postorder, inorderRight, postorderRight, rightTreeSize);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeByIndex(inorder, postorder, 0, 0, inorder.size());
    }
};