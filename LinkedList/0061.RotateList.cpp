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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* cur = head;
        int n = 0;
        for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
            n++;
        if (n == 0 || k % n == 0) 
            return head;
        k = k % n;
        ListNode* fast = head, *slow = head;
        while (k--)
            fast = fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
        
    }
};
