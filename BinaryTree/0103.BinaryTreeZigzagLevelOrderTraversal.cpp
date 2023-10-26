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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ordered_vals;
        std::vector<const TreeNode*> level_nodes;
        int depth = 1;
        if (root) {
            level_nodes.push_back(root);
        }
        while (!level_nodes.empty()) {
            std::vector<const TreeNode*> next_level_nodes;
            const int size = level_nodes.size();
            ordered_vals.push_back(std::vector<int>(size));
            for (int i = 0; i != size; ++i) {
                const int idx = depth % 2 == 1 ? i : size - 1 - i;
                ordered_vals.back()[i] = level_nodes[idx]->val;
                if (level_nodes[i]->left) {
                    next_level_nodes.push_back(level_nodes[i]->left);
                }
                if (level_nodes[i]->right) {
                    next_level_nodes.push_back(level_nodes[i]->right);
                }
            }
            ++depth;
            level_nodes = std::move(next_level_nodes);
        }
        return ordered_vals;
    }
};
