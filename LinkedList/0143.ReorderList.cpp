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
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        ListNode* middle_node = getMiddleNode(head);
        ListNode* ano_head = middle_node->next;
        middle_node->next = nullptr;
        
        ano_head = reverseList(ano_head);
        concatTwoLists(head, ano_head);
    }

private:
    ListNode* getMiddleNode(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
    
    void concatTwoLists(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);
        ListNode* head = &dummy;
        while (head1) {
            head->next = head1;
            head1 = head1->next;
            head = head->next;
            if (!head2) {
                continue;
            }
            head->next = head2;
            head2 = head2->next;
            head = head->next;
        }
    }
};
