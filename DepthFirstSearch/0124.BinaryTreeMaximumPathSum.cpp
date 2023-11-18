/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_val = std::numeric_limits<int>::min();
        dfs(root, &max_val);
        return max_val;
    }
private:
    int dfs(const TreeNode* root, int* max_val) {
        if (!root) {
            return 0;
        }
        const int left_max_val = std::max(0, dfs(root->left, max_val));
        const int right_max_val = std::max(0, dfs(root->right, max_val));
        *max_val = std::max(*max_val, left_max_val + right_max_val + root->val);
        return std::max(left_max_val, right_max_val) + root->val;
    }
};
