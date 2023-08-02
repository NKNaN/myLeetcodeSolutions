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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = new ListNode();
        pre->next = head;
        ListNode* fast = pre;
        ListNode* slow = pre;
        for (int i=0; i<n; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        tmp->next = nullptr;
        delete tmp;
        return pre->next;
    }
};