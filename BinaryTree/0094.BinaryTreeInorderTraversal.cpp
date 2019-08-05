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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderNum;
        stack<TreeNode*> visitedNodes;
        while (root || !visitedNodes.empty()) {
            while (root) {
                visitedNodes.push(root);
                root = root->left;
            }
            root = visitedNodes.top();
            visitedNodes.pop();
            inorderNum.push_back(root->val);
            root = root->right;
        }
        return inorderNum;
    }
};
