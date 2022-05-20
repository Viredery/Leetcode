/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* slow = &dummy, *fast = &dummy;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* new_head = slow->next;
        slow->next = nullptr;
        
        ListNode* pre = nullptr;
        while (new_head) {
            ListNode* next = new_head->next;
            new_head->next = pre;
            pre = new_head;
            new_head = next;
        }
        
        ListNode* cur1 = dummy.next, *cur2 = pre;
        while (cur1) {
            if (cur1->val != cur2->val) {
                return false;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }
};
