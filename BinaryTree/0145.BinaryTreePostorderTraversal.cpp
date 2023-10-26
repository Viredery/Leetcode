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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ordered_vals;
        std::stack<const TreeNode*> st;
        const TreeNode* prev_node = nullptr;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                prev_node = root;
                root = root->left;
            }
            const TreeNode* node = st.top();
            if (!node->right || node->right == prev_node) {
                ordered_vals.push_back(node->val);
                st.pop();
                prev_node = node;
            } else {
                root = node->right;
            }
        }
        return ordered_vals;
    }
};
