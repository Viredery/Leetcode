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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = getSize(head);
        if (n == 0) {
            return head;
        }
        k = k % n;
        if (k == 0) {
            return head;
        }
        ListNode* node = GetTheKthNode(head, n - k);
        ListNode* new_head = node->next;
        node->next = nullptr;
        node = GetTheKthNode(new_head, k);
        node->next = head;
        return new_head;
    }
    
private:
    int getSize(ListNode* head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }
    
    ListNode* GetTheKthNode(ListNode* head, int k) {
        int num = 1;
        while (num < k) {
            num++;
            head = head->next;
        }
        return head;
    }
};

