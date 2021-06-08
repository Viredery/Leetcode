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
        if (!head) {
            return nullptr;
        }
        ListNode* fast = head->next, *slow = head;
        while (fast != slow) {
            if (!fast || !fast->next) {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = head;
        fast = fast->next;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

