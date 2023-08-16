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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> order;
        std::stack<TreeNode*> nodes;
        while (!nodes.empty() || root) {
            while (root) {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            order.push_back(root->val);
            root = root->right;
        }
        return order;
    }
};
