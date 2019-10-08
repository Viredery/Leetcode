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
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }
private:
    int maxSum;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int maxLeft = max(0, dfs(root->left));
        int maxRight = max(0, dfs(root->right));
        maxSum = max(maxSum, root->val + maxLeft + maxRight);
        return root->val + (maxLeft > maxRight ? maxLeft : maxRight);
    }
};
