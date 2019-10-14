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
        sumRoot = 0;
        sumNumbers(root, 0);
        return sumRoot;
    }
private:
    void sumNumbers(TreeNode* root, int curVal) {
        if (!root)
            return;
        if (!root->left && !root->right)
            sumRoot += curVal * 10 + root->val;
        sumNumbers(root->left, curVal * 10 + root->val);
        sumNumbers(root->right, curVal * 10 + root->val);
    }
    int sumRoot;
};
