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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = getDepth(root);
        vector<vector<int>> res(depth, vector<int>());
        levelOrder(root, 0, res);
        return res;
    }
private:
    int getDepth(TreeNode *node) {
        return node ? std::max(getDepth(node->left), getDepth(node->right)) + 1 : 0;
    }
    
    void levelOrder(TreeNode* node, int lvl, vector<vector<int>>& lvls) {
        if (!node) return;
        lvls[lvls.size() - 1 - lvl].push_back(node->val);
        levelOrder(node->left, lvl+1, lvls);
        levelOrder(node->right, lvl+1, lvls);
    }
};
