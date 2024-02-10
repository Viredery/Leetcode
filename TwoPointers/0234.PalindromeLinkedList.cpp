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
    bool isPalindrome(ListNode* head) {
        ListNode* other_head = GetHeadOfHalfNodes(head);
        other_head = Reverse(other_head);
        while (other_head && head) {
            if (other_head->val != head->val) {
                return false;
            }
            head = head->next;
            other_head = other_head->next;
        }
        return true;
    }
private:
    ListNode* GetHeadOfHalfNodes(ListNode* head) {
        ListNode dummy_node(0, head);
        ListNode* fast = &dummy_node;
        ListNode* slow = &dummy_node;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* other_head = slow->next;
        slow->next = nullptr;
        return other_head;
    }

    ListNode* Reverse(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* pre_node = nullptr;
        ListNode* current_node = head;
        while (current_node) {
            ListNode* next_node = current_node->next;
            current_node->next = pre_node;
            pre_node = current_node;
            current_node = next_node;
        }
        return pre_node;
    }
};
