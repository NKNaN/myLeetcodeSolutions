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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* start = new ListNode(-1);
        start->next = head;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* prev = start;
        while (1) {
            a->next = b->next;
            prev->next = b;
            b->next = a;
            if (!a->next) {
                break;
            }
            prev = a;
            a = a->next;
            if (!a->next) {
                break;
            }
            b = a->next;
        }
        return start->next;
    }
};