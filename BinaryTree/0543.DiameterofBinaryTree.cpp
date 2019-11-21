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
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
private:
    int diameter = 0;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int numLeft = dfs(root->left);
        int numRight = dfs(root->right);
        
        diameter = max(diameter, numLeft + numRight);
        return max(numLeft + 1, numRight + 1);
    }
};
