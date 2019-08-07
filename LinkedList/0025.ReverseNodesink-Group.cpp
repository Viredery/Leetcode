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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        
        ListNode* cur = head->next, *pre = head, *start = head;
        while (cur != nullptr) {
            for (int i = 0; i != k; i++) {
                if (cur == nullptr)
                    return dummy.next;
                cur = cur->next;
                pre = pre->next;
            }
            pre->next = nullptr;
            pre = reverseList(start);
            pre->next = cur;
            
            start = pre;
        }
        return dummy.next;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* retained = head->next;
        ListNode* cur = head->next;
        head->next = nullptr;
        while (cur != nullptr) {
            ListNode* post = cur;
            cur = cur->next;
            post->next = head->next;
            head->next = post;
        }
        return retained;
    }
};
