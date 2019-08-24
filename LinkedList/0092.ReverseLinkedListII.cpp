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
        head = &dummy;
        ListNode* left = head, *right = head;
        int i = 1;
        while (i < m) {
            left = left->next;
            right = right->next;
            i++;
        }
        right = right->next;
        while (i < n) {
            ListNode* node = right->next;
            right->next = node->next;
            node->next = left->next;
            left->next = node;
            i++;
        }
        return dummy.next;
    }
};
