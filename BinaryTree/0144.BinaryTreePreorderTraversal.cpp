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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> ordered_vals;
        std::stack<TreeNode*> st;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                ordered_vals.push_back(root->val);
                root = root->left;
            }
            root = st.top()->right;
            st.pop();
        }
        return ordered_vals;
    }
};
