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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* mid_node = FindMidiumNode(head);
        ListNode* other_head = mid_node->next;
        mid_node->next = nullptr;
        head = sortList(head);
        other_head = sortList(other_head);

        return MergeList(head, other_head);
    }
private:
    ListNode* FindMidiumNode(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* MergeList(ListNode* one, ListNode* other) {
        ListNode dummy{0};
        ListNode* head = &dummy;
        while (one && other) {
            if (one->val <= other->val) {
                head->next = one;
                one = one->next;
            } else {
                head->next = other;
                other = other->next;
            }
            head = head->next;
        }
        if (one) {
            head->next = one;
        } else {
            head->next = other;
        }
        return dummy.next;
    }
};
