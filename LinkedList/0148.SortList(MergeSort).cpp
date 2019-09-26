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
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* head1 = head;
        ListNode* head2 = findMediumNode(head);
        
        head1 = sortList(head1);
        head2 = sortList(head2);
        return merge(head1, head2);
    }
private:
    ListNode* findMediumNode(ListNode* head) {
        ListNode* fast = head->next, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* post = slow->next;
        slow->next = nullptr;
        return post;
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);
        ListNode* ptr = &dummy;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                ptr->next = head1;
                head1 = head1->next;
            } else {
                ptr->next = head2;
                head2 = head2->next;
            }
            ptr = ptr->next;
        }
        ListNode* head = head1 ? head1 : head2;
        ptr->next = head;
        return dummy.next;
    }
};
