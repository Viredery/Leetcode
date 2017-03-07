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
    int sumNumbers(TreeNode* root) {
        if (nullptr == root)
            return 0;
        return sumNumbers(root, 0);
    }
    
    int sumNumbers(TreeNode* root, int val) {
        int leftVal = nullptr == root->left ? 0 : sumNumbers(root->left, val * 10 + root->val);
        int rightVal = nullptr == root->right ? 0 : sumNumbers(root->right, val * 10 + root->val);
        if (leftVal + rightVal == 0)
            return val * 10 + root->val;
        return leftVal + rightVal;
    }
};