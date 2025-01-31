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
    void traversal(TreeNode* prev, TreeNode* cur, int key, bool moveleft) {
        if (!cur) return;
        if (key == cur->val) {
            if (!cur->left && !cur->right) {
                if (moveleft) prev->left = nullptr;
                else prev->right = nullptr;
            } else if (!cur->left && cur->right) {
                if (moveleft) prev->left = cur->right;
                else prev->right = cur->right;
            } else if (cur->left && !cur->right) {
                if (moveleft) prev->left = cur->left;
                else prev->right = cur->left;
            } else {
                //cur->left --> cur->right->'left end'
                TreeNode* pr = cur->right;
                while(pr->left) pr = pr->left;
                pr->left = cur->left;
                
                if (moveleft) prev->left = cur->right;
                else prev->right = cur->right;
            }
            delete cur;
            return;
        }

        if (key > cur->val) traversal(cur, cur->right, key, false);
        if (key < cur->val) traversal(cur, cur->left, key, true);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        TreeNode* p = new TreeNode();
        p->left = root;
        traversal(p, root, key, true);
        return p->left;
    }
};