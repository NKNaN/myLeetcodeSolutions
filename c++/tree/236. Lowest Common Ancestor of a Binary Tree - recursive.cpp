/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool isLowest;
    TreeNode* result;
public:
    int traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (!cur) return 0;
        int count = 0;
        int leftcount = traversal(cur->left, p, q);
        int rightcount = traversal(cur->right, p, q);
        if (cur->val == p->val || cur->val == q->val) {
            ++count;
        }
        count += leftcount+rightcount;
        if (isLowest && count == 2) {
            result = cur;
            isLowest = false;
        }
        return count;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        result = root;
        isLowest = true;
        traversal(root, p, q);
        return result;
    }
};