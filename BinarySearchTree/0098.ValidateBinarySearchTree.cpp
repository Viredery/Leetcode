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
    bool isValidBST(TreeNode* root) {
        std::stack<const TreeNode*> st;
        std::optional<int> pre_val;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            const TreeNode* node = st.top();
            st.pop();
            if (pre_val && *pre_val >= node->val) {
                return false;
            }
            pre_val = node->val;
            root = node->right;
        }
        return true;
    }
};
