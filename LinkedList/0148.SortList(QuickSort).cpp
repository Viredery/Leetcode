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
    ListNode* sortList(ListNode* head) {
        quickSort(head, nullptr);
        return head;
    }
private:
    void quickSort(ListNode* head, ListNode* end) {
        if (head == end)
            return;
        ListNode* ptr = partition(head, end);
        quickSort(head, ptr);
        quickSort(ptr->next, nullptr);
    }
    
    ListNode* partition(ListNode* head, ListNode* end) {
        ListNode* node = head->next, *ptr = head;
        while (node != end) {
            if (node->val <= head->val) {
                ptr = ptr->next;
                std::swap(ptr->val, node->val);
            }
            node = node->next;
        }
        std::swap(ptr->val, head->val);
        return ptr;
    }
};
