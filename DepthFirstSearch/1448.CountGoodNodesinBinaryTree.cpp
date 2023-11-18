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
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, std::numeric_limits<int>::min(), &res);
        return res;
    }
private:
    void dfs(const TreeNode* root, int cur_max, int* count) {
        if (!root) {
            return;
        }
        if (root->val >= cur_max) {
            ++(*count);
        }
        cur_max = std::max(cur_max, root->val);
        dfs(root->left, cur_max, count);
        dfs(root->right, cur_max, count);
    }
};
