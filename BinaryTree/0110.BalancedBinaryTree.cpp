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
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
private:
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftHeight = height(root->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = height(root->right);
        if (rightHeight == -1)
            return -1;
        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        return max(leftHeight, rightHeight) + 1;
    }
};
