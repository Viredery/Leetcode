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
        ListNode *result = NULL;
        int carry = 0;
        ListNode *p;
        while(l1 && l2) {
            int x = l1->val + l2->val + carry;
            int result_x;
            x < 10 ? (result_x = x, carry = 0) : (result_x = x - 10, carry = 1);
            ListNode *new_node = new ListNode(result_x);
            if(result == NULL) {
                result = new_node;
                p = result;
            } else {
                p->next = new_node;
                p = p->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int x = l1->val + carry;
            int result_x;
            x < 10 ? (result_x = x, carry = 0) : (result_x = 0, carry = 1);
            ListNode * new_node = new ListNode(result_x);
            if(result == NULL) {
                result = new_node;
                p = result;
            } else {
                p->next = new_node;
                p = p->next;
            }
            l1 = l1->next;
        }
        while(l2) {
            int x = l2->val + carry;
            int result_x;
            x < 10 ? (result_x = x, carry = 0) : (result_x = 0, carry = 1);
            ListNode * new_node = new ListNode(result_x);
            if(result == NULL) {
                result = new_node;
                p = result;
            } else {
                p->next = new_node;
                p = p->next;
            }
            l2 = l2->next;
        }
        if(carry == 1) {
            ListNode *new_node = new ListNode(1);
            p->next = new_node;
        }
        return result;
    }
};
