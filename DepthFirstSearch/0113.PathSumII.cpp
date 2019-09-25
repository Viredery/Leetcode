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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        calcPathSum(root, sum, 0, path, paths);
        return paths;
    }
private:
    void calcPathSum(TreeNode* root, int sum, int val,
                     vector<int>& path, vector<vector<int>>& paths) {
        if (root == nullptr)
            return;
        val += root->val;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (val == sum)
                paths.push_back(path);
        } else {
            calcPathSum(root->left, sum, val, path, paths);
            calcPathSum(root->right, sum, val, path, paths);
        }
        path.pop_back();
    }
};
