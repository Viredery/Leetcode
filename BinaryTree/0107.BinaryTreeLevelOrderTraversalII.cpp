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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        const int depth = GetDepth(root);
        std::vector<std::vector<int>> ordered_vals(depth);
        DepthFirstSearch(root, 0, &ordered_vals);
        return ordered_vals;
    }
private:
    int GetDepth(const TreeNode* root) const {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        return std::max(GetDepth(root->left), GetDepth(root->right)) + 1;
    }

    void DepthFirstSearch(const TreeNode* root, 
                          int depth,
                          std::vector<std::vector<int>>* ordered_vals) const {
        if (!root) {
            return;
        }
        const int reversed_idx = ordered_vals->size() - 1 - depth;
        ordered_vals->at(reversed_idx).push_back(root->val);
        DepthFirstSearch(root->left, depth + 1, ordered_vals);
        DepthFirstSearch(root->right, depth + 1, ordered_vals);
    }
};
