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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int cur_pos = 0;
        return DepthFirstSearch(preorder,
                                &cur_pos, 
                                std::numeric_limits<int>::min(),
                                std::numeric_limits<int>::max());
    }
private:
    TreeNode* DepthFirstSearch(const vector<int>& preorder,
                               int* cur_pos,
                               int min_value,
                               int max_value) {
        if (*cur_pos == preorder.size()) {
            return nullptr;
        }
        const int val = preorder[*cur_pos];
        if (val < min_value || val > max_value) {
            return nullptr;
        }
        ++(*cur_pos);
        TreeNode* root = new TreeNode(val);
        root->left = DepthFirstSearch(preorder, cur_pos, min_value, val);
        root->right = DepthFirstSearch(preorder, cur_pos, val, max_value);
        return root;
    }
};
