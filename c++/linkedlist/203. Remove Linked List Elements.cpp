/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        }
        ListNode* pl = head;
        while (head && head->val == val) {
            head = head->next;
            pl = head;
        }
        if (!pl) {
            return pl;
        }
        while (pl->next) {
            while (pl->next && pl->next->val == val) {
                deleteNode(pl);
            } 
            if (pl->next){
                pl = pl->next;
            } else {
                break;
            }
        }
        return head;
    }

    void deleteNode(ListNode* pl) {
        ListNode* nn = pl->next->next;
        ListNode* n = pl->next;
        n->next = nullptr;
        pl->next = nn;
        delete n;
    }
};