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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftMinDepth = minDepth(root->left);
        if (leftMinDepth == 0)
            return rightMinDepth + 1;
        int rightMinDepth = minDepth(root->right);
        if (rightMinDepth == 0)
            return leftMinDepth + 1;
        return min(leftMinDepth, rightMinDepth) + 1;
    }
};
