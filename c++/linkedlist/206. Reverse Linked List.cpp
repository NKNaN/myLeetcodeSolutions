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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* b = head;
        ListNode* c = head;
        b = b->next;
        while (b) {
            while (c->next != b) {
                c = c->next;
            }
            c->next = b->next;
            b->next = head;
            head = b;
            b = c->next;
        }
        return head;
    }
};