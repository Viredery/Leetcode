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
        if (!head) return nullptr;
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        
        ListNode* node = head;
        int n = 0;
        while (node->next) {
            n++;
            node = node->next;
        }
        k = k % n;
        if (k == 0)
            return dummy.next;
        node = head;
        for (int i = 0; i < n - k; i++) {
            node = node->next;
        }
        
        ListNode* last = node->next;
        node->next = nullptr;
        head = last;
        while (last->next) {
            last = last->next;
        }
        last->next = dummy.next;
        return head;
        
    }
};
