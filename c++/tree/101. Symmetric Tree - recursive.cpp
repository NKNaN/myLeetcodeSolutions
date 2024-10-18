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
    bool isSymmetric(TreeNode* root) {
        TreeNode* root_cp = copyTree(root);
        inverseTree(root_cp);
        bool ret = eqTree(root_cp, root);
        deleteTree(root_cp);
        return ret;
    }
    TreeNode* copyTree(TreeNode* root) {
        if (root) {
            TreeNode* out = new TreeNode(root->val);
            out->left = copyTree(root->left);
            out->right = copyTree(root->right);
            return out;
        }
        return nullptr;
    }
    void inverseTree(TreeNode* root) {
        if (root) {
            TreeNode* pr = root;
            swap(pr->left, pr->right);
            inverseTree(pr->left);
            inverseTree(pr->right);
        }
    }
    bool eqTree(TreeNode* a, TreeNode* b) {
        if (a && b) {
            if (a->val == b->val) return eqTree(a->left, b->left) & eqTree(a->right, b->right);
            else return false;
        } else if (a) {
            return false;
        } else if (b) {
            return false;
        } else {
            return true;
        }
    }
    void deleteTree(TreeNode* root) {
        if (root) {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }
};