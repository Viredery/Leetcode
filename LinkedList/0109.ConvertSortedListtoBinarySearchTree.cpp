/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        vector<ListNode*> pair = getMiddle(head);
        ListNode* left = pair[0], *right = pair[1];
        
        TreeNode* node = new TreeNode(right->val);
        node->left = sortedListToBST(left);
        node->right = sortedListToBST(right->next);
        return node;
    }
private:
    vector<ListNode*> getMiddle(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        ListNode* fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* node = slow->next;
        slow->next = nullptr;
        return {dummy.next, node};
    }
};
