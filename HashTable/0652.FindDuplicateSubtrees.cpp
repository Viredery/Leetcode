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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
private:
    vector<TreeNode*> res;
    unordered_map<string, int> hash;
    
    string dfs(TreeNode* root) {
        if (!root)
            return "#";
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        string key = to_string(root->val) + "," + left + "," + right;
        if (++hash[key] == 2)
            res.push_back(root);
        return key;
    }
};
