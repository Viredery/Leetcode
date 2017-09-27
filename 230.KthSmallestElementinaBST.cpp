/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> st;
        while (root) {
            st.push_back(root);
            root = root->left;
        }
        int i = 0;
        while (k != 0) {
            TreeNode* node = st.back();
            st.pop_back();
            if (--k == 0)
                return node->val;
            node = node->right;
            while (node) {
                st.push_back(node);
                node = node->left;
            }
        }
        return -1;
    }
};