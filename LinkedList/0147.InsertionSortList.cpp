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
    ListNode* insertionSortList(ListNode* head) {
        if (nullptr == head)
             return head;
        ListNode headNode(0);
        headNode.next = head;
        head = &headNode;
        ListNode *lastSortedPtr = head->next, *currPtr = head->next->next;
        while (nullptr != currPtr) {
            lastSortedPtr->next = currPtr->next;
            auto ptr = head;
            for (; ptr != lastSortedPtr; ptr = ptr->next) {
                if (currPtr->val < ptr->next->val) {
                    currPtr->next = ptr->next;
                    ptr->next = currPtr;
                    break;
                }
            }
            if (ptr == lastSortedPtr) {
                currPtr->next = lastSortedPtr->next;
                lastSortedPtr->next = currPtr;
                lastSortedPtr = lastSortedPtr->next;
            }
            currPtr = lastSortedPtr->next;
        }
        return head->next;
    }
};
