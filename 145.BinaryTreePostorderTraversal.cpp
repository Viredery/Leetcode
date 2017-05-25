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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> arr;
        TreeNode *markNode = nullptr;
        while (!arr.empty() || root) {
            while (root) {
                markNode = root;
                arr.push(root);
                root = root->left;
            }
            while (!arr.empty() && (arr.top()->right == nullptr || arr.top()->right == markNode)) {
                TreeNode *node = arr.top();
                res.push_back(node->val);
                markNode = node;
                arr.pop();
            }
            if (!arr.empty())
                root = arr.top()->right;
        }
        return res;
    }
};
