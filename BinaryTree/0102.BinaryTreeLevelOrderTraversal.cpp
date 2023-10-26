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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> node_values;
        if (!root) {
            return node_values;
        }
        std::queue<const TreeNode*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            const int num_nodes = node_queue.size();
            std::vector<int> level_values;
            level_values.reserve(num_nodes);
            for (int i = 0; i != num_nodes; ++i) {
                level_values.push_back(node_queue.front()->val);
                if (node_queue.front()->left) {
                    node_queue.push(node_queue.front()->left);
                }
                if (node_queue.front()->right) {
                    node_queue.push(node_queue.front()->right);
                }
                node_queue.pop();
            }
            node_values.push_back(std::move(level_values));
        }
        return node_values;
    }
};
