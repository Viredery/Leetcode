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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy_node{0, head};
        ListNode* pre = &dummy_node;
        for (int i = 1; i < left; ++i) {
            pre = pre->next;
        }
        ListNode* last = &dummy_node;
        for (int i = 1; i <= right; ++i) {
            last = last->next;
        }
        ListNode* pre_next = pre->next;
        ListNode* last_next = last->next;
        ListNode* pre_node = pre;
        ListNode* cur_node = pre_node->next;
        while (pre_node != last) {
            ListNode* next = cur_node->next;
            cur_node->next = pre_node;
            pre_node = cur_node;
            cur_node = next;
        }
        pre->next = last;
        pre_next->next = last_next;

        return dummy_node.next;
    }
};
