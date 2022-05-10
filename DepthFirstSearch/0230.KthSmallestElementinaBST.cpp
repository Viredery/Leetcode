/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> path;
        while (root != nullptr || !path.empty()) {
            while (root) {
                path.push(root);
                root = root->left;
            }
            root = path.top();
            path.pop();
            if (--k == 0) {
                return root->val;
            }
            root = root->right;
        }
        return 0;
    }
};
