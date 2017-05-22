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
    Solution() { ptrNode = nullptr; }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *curNode = head;
        int num = 0;
        while (curNode != nullptr) {
            curNode = curNode->next;
            num++;
        }
        ptrNode = head;
        return constructTree(0, num-1);
    }
private:
    TreeNode *constructTree(int left, int right) {
        if (left > right)
            return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode *leftNode = constructTree(left, mid-1);
        TreeNode *node = new TreeNode(ptrNode->val);
        node->left = leftNode;
        ptrNode = ptrNode->next;
        TreeNode *rightNode = constructTree(mid+1, right);
        node->right = rightNode;
        
        return node;
    }
    ListNode *ptrNode;
};