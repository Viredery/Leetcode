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
        if (nullptr == root)
            return true;
        stack<TreeNode*> s;
        while (root) {
            s.push(root);
            root = root->left;
        }
        int preVal = s.top()->val;
        root = s.top()->right;
        s.pop();
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;                
            }
            int val = s.top()->val;
            if (val <= preVal)
                return false;
            preVal = val;
            root = s.top()->right;
            s.pop();
        }
        return true;
    }
};