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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        std::stack<TreeNode*> st;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            TreeNode* node = st.top();
            if (prev && prev->val > node->val) {
                if (!first) {
                    first = prev;   
                }
                second = node;
            }
            prev = node;
            root = node->right;
            st.pop();
        }
        std::swap(first->val, second->val);
    }
};
