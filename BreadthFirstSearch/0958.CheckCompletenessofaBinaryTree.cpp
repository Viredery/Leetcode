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
    bool isCompleteTree(TreeNode* root) {
        std::queue<TreeNode*> node_queue;
        node_queue.push(root);
        bool mark_nullptr = false;
        while (!node_queue.empty()) {
            TreeNode* node = node_queue.front();
            node_queue.pop();
            if (node && mark_nullptr) {
                return false;
            }
            if (node) {
                node_queue.push(node->left);
                node_queue.push(node->right);
            } else {
                mark_nullptr = true;
            }
        }
        return true;
    }
};
