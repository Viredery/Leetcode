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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        ListNode* slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *otherHead = slow->next;
        slow->next = nullptr;

        otherHead = reverseList(otherHead);
        
        while (otherHead) {
            ListNode* tmp = otherHead->next;
            otherHead->next = head->next;
            head->next = otherHead;
            head = otherHead->next;
            otherHead = tmp;
        }
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *node = head->next;
        head->next = nullptr;
        while (node) {
            ListNode* tmp = node->next;
            node->next = head;
            head = node;
            node = tmp;
        }
        return head;
    }
};