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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        
        while (head->next) {
            head = head->next;
            ListNode *node = head->next;
            while (node && node->val == head->val)
                node = node->next;
            head->next = node;
        }
        return dummy.next;
    }
};
