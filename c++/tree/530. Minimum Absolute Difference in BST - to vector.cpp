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
    vector<int> arr;
    void BSTtoVec(TreeNode* node) {
        if (!node->left && !node->right) {
            arr.push_back(node->val);
            return;
        }
        if (node->left) BSTtoVec(node->left);
        arr.push_back(node->val);
        if (node->right) BSTtoVec(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        BSTtoVec(root);
        int tmp_min = INT_MAX;
        for (int i=1; i<arr.size(); ++i) {
            if (tmp_min > arr[i] - arr[i-1]) 
                tmp_min = arr[i] - arr[i-1];
        }
        return tmp_min;
    }
};