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
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *slow = head, *fast = head->next;
        int difference = 1;
        while (fast != nullptr && fast->next != nullptr && fast != slow) {
            fast = fast->next->next;
            slow = slow->next;
            difference++;
        }
        if (fast != slow)
            return nullptr;
        slow = fast = head;
        for (int i = 0; i != difference; i++)
            fast = fast->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
