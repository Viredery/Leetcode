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
    vector<int> rightSideView(TreeNode* root) {
        list<TreeNode*> que;
        vector<int> res;
        if (root == nullptr)
            return {};
        que.push_back(root);
        while (!que.empty()) {
            res.push_back(que.back()->val);
            int size = que.size();
            for (int _ = 0; _ != size; _++) {
                TreeNode* node = que.front();
                que.pop_front();
                if (node->left)
                    que.push_back(node->left);
                if (node->right)
                    que.push_back(node->right);
            }
        }
        return res;
    }
};