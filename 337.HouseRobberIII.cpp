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
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
private:
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0}; // based on root; based on w/o root
        int val = root->val;
        pair<int, int> leftRes, rightRes;

        leftRes = dfs(root->left);
        rightRes = dfs(root->right);
        
        int childVal = max(leftRes.first, leftRes.second) + max(rightRes.first, rightRes.second);
        val = root->val + leftRes.second + rightRes.second;
        return {val, childVal};
    }
};
