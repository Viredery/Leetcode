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
        if (root != nullptr)
            flattenSubTree(root);
    }
private:
    TreeNode *flattenSubTree(TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr)
            return root;
        if (root->left != nullptr && root->right == nullptr) {
            root->right = root->left;
            root->left = nullptr;
            return flattenSubTree(root->right);
        }
        if (root->left == nullptr)
            return flattenSubTree(root->right);
        TreeNode *node = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode *preNode = flattenSubTree(root->right);
        preNode->right = node;
        return flattenSubTree(node);
    }
};
