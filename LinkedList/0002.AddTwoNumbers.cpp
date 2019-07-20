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
        int carry = 0;
        ListNode dummyHead = ListNode(0), *ptr = &dummyHead;
        while (l1 != nullptr || l2 != nullptr) {
            int x1 = l1 != nullptr ? l1->val : 0;
            int x2 = l2 != nullptr ? l2->val : 0;
            
            ListNode * curPtr = new ListNode((x1 + x2 + carry) % 10);
            carry = (x1 + x2 + carry) / 10;
            
            ptr->next = curPtr;
            ptr = ptr->next;
            
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
        }
        if (carry == 1)
            ptr->next = new ListNode(1);
        return dummyHead.next;
    }
};
