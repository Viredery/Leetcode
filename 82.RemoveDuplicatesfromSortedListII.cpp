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
        ListNode* headNode = new ListNode(0);
        headNode->next = head;
        head = headNode;
        ListNode *pre = head;
        while (pre->next) {
            ListNode *cur = pre->next->next;
            bool mark = false;
            while (cur && cur->val == pre->next->val) {
                cur = cur->next;
                mark = true;
            }
            if (mark == true)
                pre->next = cur;
            else {
                pre->next->next = cur;
                pre = pre->next;
            }
        }
        ListNode *result = head->next;
        delete head;
        return result;
    }
};