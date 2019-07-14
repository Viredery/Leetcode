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
        vector<int> postorderNum;
        stack<TreeNode*> visitedNodes;
        TreeNode* lastVisited = nullptr;
        while (!visitedNodes.empty() || root) {
            while (root) {
                visitedNodes.push(root);
                root = root->left;
            }
            if (visitedNodes.empty())
                break;
            auto node = visitedNodes.top();
            if (!node->right || node->right == lastVisited) {
                visitedNodes.pop();
                postorderNum.push_back(node->val);
                lastVisited = node;
            } else {
                root = node->right;
            }
        }
        return postorderNum;
    }
};