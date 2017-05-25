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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> arr;
        while (!arr.empty() || root) {
            while (root) {
                res.push_back(root->val);
                arr.push(root);
                root = root->left;
            }
            if (!arr.empty()) {
                root = arr.top()->right;
                arr.pop();
            }
        }
        return res;
    }
};
