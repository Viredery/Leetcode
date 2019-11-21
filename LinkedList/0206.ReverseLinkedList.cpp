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
    ListNode* reverseList(ListNode* head) {
        if (!head) 
            return nullptr;
        ListNode* pre = head, *cur = head->next;
        while (cur) {
            ListNode* post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        head->next = nullptr;
        return pre;
    }
};
