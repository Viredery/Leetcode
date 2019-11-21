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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* a = &dummy, *c = &dummy;
        for (int _ = 0; _ != m - 1; _++)
            a = a->next;
        for (int _ = 0; _ != n; _++)
            c = c->next;
        ListNode* b = a->next, *d = c->next;
        
        ListNode* pre = b, *ptr = b->next;
        while (ptr != d) {
            ListNode* post = ptr->next;
            ptr->next = pre;
            pre = ptr;
            ptr = post;
        }
        b->next = d;
        a->next = c;
        return dummy.next;
    }
};
