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
    int minDepth(TreeNode* root) {
        std::queue<const TreeNode*> node_queue;
        if (!root) {
            return 0;
        }
        int depth = 1;
        node_queue.push(root);
        while (!node_queue.empty()) {
            const int num_nodes = node_queue.size();
            for (int i = 0; i != num_nodes; ++i) {
                const TreeNode* node = node_queue.front();
                node_queue.pop();
                if (!node->left && !node->right) {
                    return depth;
                }
                if (node->left) {
                    node_queue.push(node->left);
                }
                if (node->right) {
                    node_queue.push(node->right);
                }
            }
            depth += 1;
        }
        return depth;
    }
};
