class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode headNode(0);
        headNode.next = head;
        head = &headNode;
        ListNode *cur = head, *pre = head;
        while (cur->next) {
            if (cur->next->val < x) {
                ListNode *movePtr = cur->next;
                cur->next = cur->next->next;
                ListNode *nonvisited = cur->next;
                
                movePtr->next = pre->next;
                pre->next = movePtr;
                pre = pre->next;
                if (nonvisited != cur->next)
                    cur = cur->next;
            } else
                cur = cur->next;
        }
        return head->next;
    }
};