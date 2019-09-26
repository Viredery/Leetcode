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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        if (!root->left)
            return flatten(root->right);
        
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* node = root->right;
        while (node->right)
            node = node->right;
        node->right = tmp;
        
        flatten(root->right);
    }
};
