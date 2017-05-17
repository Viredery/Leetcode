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
    void recoverTree(TreeNode* root) {
        stack<TreeNode *> visitedPath;
        TreeNode *firstNode = nullptr, *secondNode = nullptr, *tmpNode = new TreeNode(INT_MIN);
        TreeNode *preNode = tmpNode;
        while (!visitedPath.empty() || root != nullptr) {
            while (root != nullptr) {
                visitedPath.push(root);
                root = root->left;
            }
            TreeNode *currNode = visitedPath.top();
            if (preNode->val > currNode->val) {
                if (firstNode == nullptr) {
                    firstNode = preNode;
                    secondNode = currNode;
                } else {
                    secondNode = currNode;
                }
            }
            preNode = currNode;
            visitedPath.pop();
            root = currNode->right;
        }
        swap(firstNode->val, secondNode->val);
        delete tmpNode;
    }
};
