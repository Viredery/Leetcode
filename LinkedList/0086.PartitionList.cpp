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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummyL(0), dummyR(0);
        dummyL.next = head;
        head = &dummyL; 
        ListNode* headR = &dummyR;
        while (head->next) {
            if (head->next->val < x)
                head = head->next;
            else {
                headR->next = head->next;
                headR = headR->next;
                head->next = head->next->next;
            }
        }
        headR->next = nullptr;
        head->next = dummyR.next;
        return dummyL.next;
    }
};
