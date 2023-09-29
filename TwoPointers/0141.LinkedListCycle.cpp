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
    bool hasCycle(ListNode *head) {
        ListNode dummy;
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast && fast == slow) {
                return true;
            }
        }
        return false;
    }
};
