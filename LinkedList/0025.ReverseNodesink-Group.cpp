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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy_head(0, head);
        ListNode* pre_head = &dummy_head;
        const int count = GetCount(head);
        
        for (int i = 0; i + k <= count; i += k) {
            pre_head = reverseNextKNodes(pre_head, k);
        }
        return dummy_head.next;
    }
private:
    int GetCount(ListNode* head) {
        int count = 0;
        while (head) {
            ++count;
            head = head->next;
        }
        return count;
    }

    ListNode* reverseNextKNodes(ListNode* pre_head, int k) {
        ListNode* pre = pre_head;
        ListNode* cur = pre->next;
        for (int _ = 0; _ != k; ++_) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ListNode* original_next = pre_head->next;
        pre_head->next->next = cur;
        pre_head->next = pre;
        return original_next;
    }
};
