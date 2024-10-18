/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        if (root->children.empty()) return 1;
        int tmp = 0;
        for (int i=0; i<root->children.size(); ++i) {
            int val = maxDepth(root->children[i]);
            if (tmp < val) tmp = val;
        }
        return tmp + 1;
    }
};