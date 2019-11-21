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
        TreeNode* firstNode = nullptr, *secondNode = nullptr, *pre = nullptr;
        vector<TreeNode*> paths;
        while (root || !paths.empty()) {
            while (root) {
                paths.push_back(root);
                root = root->left;
            }
            TreeNode* node = paths.back();
            paths.pop_back();
            if (pre && pre->val >= node->val) {
                if (!firstNode)
                    firstNode = pre;
                secondNode = node;
            }
            pre = node;
            root = node->right;
        }
        swap(firstNode->val, secondNode->val);
        
    }
};
