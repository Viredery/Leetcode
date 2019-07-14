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
        while (!visitedNodes.empty() || root) {
            while (root) {
                visitedNodes.push(root);
                root = root->left;
            }
            if (!visitedNodes.empty()) {
                auto node = visitedNodes.top();
                visitedNodes.pop();
                
                inorderNum.push_back(node->val);
                root = node->right;
            }
        }
        return inorderNum;
    }
};