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
        vector<int> preorderNum;
        stack<TreeNode*> visitedNodes;
        
        while (!visitedNodes.empty() || root) {
            while (root) {
                visitedNodes.push(root);
                preorderNum.push_back(root->val);
                root = root->left;
            }
            if (!visitedNodes.empty()) {
                root = visitedNodes.top()->right;
                visitedNodes.pop();
            }
        }
        
        return preorderNum;
    }
};