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
    int maxPathSum(TreeNode* root) {
        int curMaxSum = INT_MIN;
        maxPathSum(root, curMaxSum);
        return curMaxSum;
    }
    int maxPathSum(TreeNode* root, int& curMaxSum) {
        if (root == nullptr)
            return 0;
        int maxLeft = max(0, maxPathSum(root->left, curMaxSum));
        int maxRight = max(0, maxPathSum(root->right, curMaxSum));
        curMaxSum = max(curMaxSum, maxLeft + maxRight + root->val);
        return max(maxLeft, maxRight) + root->val;
    }
};
