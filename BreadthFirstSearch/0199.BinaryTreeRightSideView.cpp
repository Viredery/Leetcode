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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> views;
        if (!root) {
            return views;
        }
        std::queue<TreeNode*> level_nodes;
        level_nodes.push(root);
        while (!level_nodes.empty()) {
            const int length = level_nodes.size();
            for (int i = 0; i != length; ++i) {
                TreeNode* node = level_nodes.front();
                level_nodes.pop();
                if (i + 1 == length) {
                    views.push_back(node->val);
                }
                if (node->left) {
                    level_nodes.push(node->left);
                }
                if (node->right) {
                    level_nodes.push(node->right);
                }
            }
        }
        return views;
    }
};
