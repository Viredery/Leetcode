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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        head = &dummy;
        
        ListNode* pre = head, *cur = head, *post = head->next;
        while (post && post->next) {
            post = post->next->next;
            cur = cur->next;
            pre->next = cur->next;
            pre->next->next = cur;
            cur->next = post;
            pre = cur;
        }
        return dummy.next;
    }
};
