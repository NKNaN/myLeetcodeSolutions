/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool start = true;
        while (1) {
            if (fast == nullptr || fast->next == nullptr) {
                return NULL;
            }
            // cout<<"fast: "<<fast->val<<"slow: "<<slow->val<<endl;
            start = false;
            // fast移动
            fast = fast->next->next;
            // slow移动
            slow = slow->next;
            // 判断fast是否追上slow
            if (!start && slow == fast) {
                // 相遇点
                break;
            }
        }
        ListNode* p1 = head;
        ListNode* p2 = fast;
        while (p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};