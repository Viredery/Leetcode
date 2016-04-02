/**
 * Runtime: 8 ms
 * Your runtime beats 83.21% of cppsubmissions.
 */

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
        if(head == NULL)
            return head;
        ListNode *prev, *end;
        prev = end = head;
        int nums = 1;
        for(; k != 0; k--)
            if(end->next != NULL) {
                end = end->next;
                nums++;
            } else {
                end = head;
                k = (k - 1) % nums + 1;
            }
        while(end->next != NULL) {
            end = end->next;
            prev = prev->next;
        }
        end->next = head;
        head = prev->next;
        prev->next = NULL;
        return head;
    }
};
