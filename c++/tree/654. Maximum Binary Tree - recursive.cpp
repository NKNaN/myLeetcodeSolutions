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
private:
    TreeNode* constructMaximumBinaryTreeIdx(vector<int>& nums, int start, int end) {
        if (end == start) return nullptr;
        int maxIdx = findMaxIdx(nums, start, end);
        // cout<<maxIdx<<endl;
        TreeNode* root = new TreeNode(nums[maxIdx]);
        if (end - start == 1) return root;
        TreeNode* left = constructMaximumBinaryTreeIdx(nums, start, maxIdx);
        TreeNode* right = constructMaximumBinaryTreeIdx(nums, maxIdx + 1, end);
        root->left = left;
        root->right = right;
        return root;
    }
    int findMaxIdx(vector<int>& nums, int start, int end) {
        int max = INT_MIN;
        int max_idx = start;
        for (int i = start; i<end; ++i) {
            if (nums[i] > max) {
                max = nums[i];
                max_idx = i;
            }
        }
        return max_idx; 
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        return constructMaximumBinaryTreeIdx(nums, 0, nums.size());
    }
};