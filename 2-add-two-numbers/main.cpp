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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int t = 0;
        ListNode* first = nullptr;
        ListNode* pre = nullptr;
        while(l1 || l2) {
            int val = t;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            t = val / 10;
            val = val % 10;
            ListNode* q = new ListNode(val);
            if (pre) {
                pre->next = q;
            } else {
                first = q;
            }
            pre = q;
        }
        if (t != 0) {
            ListNode* q = new ListNode(t);
            pre->next = q;
        }
        return first;
    }
};
