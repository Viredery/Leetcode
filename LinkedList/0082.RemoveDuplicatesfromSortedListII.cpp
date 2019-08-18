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
            ListNode* left = head->next;
            ListNode* right = left->next;
            bool duplicate = false;
            while (right && right->val == left->val) {
                duplicate = true;
                right = right->next;
            }
            if (duplicate)
                head->next = right;
            else
                head = head->next;
        }
        return dummy.next;
    }
};
