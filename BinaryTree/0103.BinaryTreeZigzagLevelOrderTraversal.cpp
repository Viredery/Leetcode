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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        list<TreeNode*> level;
        if (root)
            level.push_back(root);
        bool left2right = true;
        while (!level.empty()) {
            int size = level.size();
            vector<int> res_lvl(size, 0);
            for (int i = 0; i != size; i++) {
                TreeNode* node = level.front();
                level.pop_front();
                
                int idx = left2right ? i : size - 1 - i;
                res_lvl[idx] = node->val;
                
                if (node->left)
                    level.push_back(node->left);
                if (node->right)
                    level.push_back(node->right);
            }
            left2right = !left2right;
            res.push_back(std::move(res_lvl));
        }
        return res;
    }
};
