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
    bool hasPathSum(TreeNode* root, int sum) {
        existPathSum = false;
        visitPath(root, sum, 0);
        return existPathSum;
    }
private:
    bool existPathSum;
    void visitPath(TreeNode* root, int sum, int val) {
        if (root == nullptr)
            return;
        val += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (val == sum)
                existPathSum = true;
            return;
        }
        visitPath(root->left, sum, val);
        visitPath(root->right, sum, val);
    }
};
