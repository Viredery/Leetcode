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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        TreeNode* l = root->left, *r = root->right;
        stack<TreeNode*> left, right;
        
        while (l || r || !left.empty() || !right.empty()) {
            while (l && r) {
                left.push(l), l = l->left;
                right.push(r), r = r->right;
            }
            
            if (l || r)
                return false;
            
            l = left.top(), left.pop();
            r = right.top(), right.pop();
            
            if (l->val != r->val)
                return false;
            
            l = l->right, r = r->left;
        }
        return true;
    }
};
