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
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> paths;
        dfs(root, "", &paths);
        return paths;
    }
private:
    void dfs(const TreeNode* root, std::string current_path, std::vector<std::string>* paths) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            paths->push_back(current_path + std::to_string(root->val));
            return;
        }
        dfs(root->left, current_path + std::to_string(root->val) + "->", paths);
        dfs(root->right, current_path + std::to_string(root->val) + "->", paths);
    }
};
