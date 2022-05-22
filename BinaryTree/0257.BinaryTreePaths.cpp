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
        std::vector<string> paths;
        binaryTreePaths(root, "", &paths);
        return paths;
    }
private:
    void binaryTreePaths(TreeNode* root, 
                         const std::string& cur_path, 
                         std::vector<string>* paths) {
        std::string cur_val = std::to_string(root->val);
        if (!root->left && !root->right) {
            paths->push_back(cur_path + cur_val);
        }
        if (root->left) {
            binaryTreePaths(root->left, cur_path + cur_val + "->", paths);
        }
        if (root->right) {
            binaryTreePaths(root->right, cur_path + cur_val + "->", paths);
        }
    }
};
