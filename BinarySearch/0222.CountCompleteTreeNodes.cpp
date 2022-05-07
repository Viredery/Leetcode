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
    int countNodes(TreeNode* root) {
        int height = 0;
        TreeNode* node = root;
        while (node) {
            height++;
            node = node->left;
        }
        return countNodes(root, height);
    }
private:
    int countNodes(TreeNode* root, int tree_height) {
        if (!root) {
            return 0;
        }
        int height = 1;
        TreeNode* node = root->left;
        while (node) {
            height++;
            node = node->right;
        }
        if (height == tree_height) {
            return std::pow(2, height - 1) + countNodes(root->right, tree_height - 1);
        } else {
            return std::pow(2, height - 1) + countNodes(root->left, tree_height - 1);
        }
    }
};
