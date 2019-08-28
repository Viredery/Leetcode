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
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> paths;
        TreeNode* pre = nullptr;
        while (root || !paths.empty()) {
            while (root) {
                paths.push_back(root);
                root = root->left;
            }
            TreeNode* node = paths.back();
            paths.pop_back();
            if (pre && pre->val >= node->val)
                return false;
            pre = node;
            root = node->right;
        }
        return true;
    }
};
