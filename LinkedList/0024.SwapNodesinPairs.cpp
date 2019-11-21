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
        for (ListNode* ptr = &dummy; ptr->next && ptr->next->next; ptr = ptr->next->next) {
            ListNode* cur = ptr->next, *post = cur->next;
            cur->next = post->next;
            post->next = cur;
            ptr->next = post;
        }
        return dummy.next;
    }
};
