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
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0, head);
        head = &dummy;
        ListNode* pre = nullptr;
        while (head->next) {
            ListNode* node = head->next;
            head->next = head->next->next;
            node->next = pre;
            pre = node;
        }
        return pre;
    }
};
