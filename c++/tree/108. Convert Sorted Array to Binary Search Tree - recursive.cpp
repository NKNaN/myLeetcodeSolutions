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
    TreeNode* traversal(vector<int>& nums, int lo, int hi) {
        // cout<<"lo: "<<lo<<" hi: "<<hi<<endl;
        if (hi == lo) return nullptr;
        if (hi - lo == 1) return new TreeNode(nums[lo]);
        int mid = (lo + hi) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, lo, mid);
        root->right = traversal(nums, mid+1, hi);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        int lo = 0;
        int hi = nums.size();
        TreeNode* root = traversal(nums, lo, hi);
        return root;
    }
};