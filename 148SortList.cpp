/**
 * Runtime: 60 ms
 * Your runtime beats 50.46% of cppsubmissions.
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* formerHead = head;
        ListNode* latterHead = getMiddleNode(head);
        formerHead = sortList(formerHead);
        latterHead = sortList(latterHead);
        return Merge(formerHead, latterHead);
    }
    ListNode* getMiddleNode(ListNode* head) {
        ListNode *fast, *slow, *prev;
        prev = head;
        fast = slow = head->next;
        while(true) {
            if(fast != NULL && fast->next != NULL)
                fast = fast->next->next;
            else
                break;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        return slow;
    }
    ListNode* Merge(ListNode* formerHead, ListNode* latterHead) {
        ListNode result(0);
        ListNode* current_p = &result;
        while(true) {
            if(formerHead != NULL && latterHead != NULL) {
                if(formerHead->val < latterHead->val) {
                    current_p->next = formerHead;
                    current_p = formerHead;
                    formerHead = formerHead->next;
                } else {
                    current_p->next = latterHead;
                    current_p = latterHead;
                    latterHead = latterHead->next;
                }
            } else {
                if(formerHead == NULL)
                    current_p->next = latterHead;
                else
                    current_p->next = formerHead;
                break;
            }
        }
        return result.next;
    }
};
