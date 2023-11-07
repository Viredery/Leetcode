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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || preorder.size() != inorder.size()) {
            return nullptr;
        }
        std::unordered_map<int, int> inorder_indexes;
        for (int i = 0; i != inorder.size(); ++i) {
            inorder_indexes[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorder_indexes);
    }
private:
    TreeNode* buildTree(const vector<int>& preorder, int pre_left, int pre_right, 
                        const vector<int>& inorder, int in_left, int in_right,
                        const std::unordered_map<int, int>& inorder_indexes) {
        if (pre_left > pre_right) {
            return nullptr;
        }
        const int pre_val = preorder[pre_left];
        TreeNode* root = new TreeNode(pre_val);
        const int in_idx = inorder_indexes.at(pre_val);
        const int left_size = in_idx - in_left;
        root->left = buildTree(preorder, pre_left + 1, pre_left + left_size,
                               inorder, in_left, in_idx - 1, 
                               inorder_indexes);
        root->right = buildTree(preorder, pre_left + left_size + 1, pre_right, 
                                inorder, in_idx + 1, in_right, 
                                inorder_indexes);
        return root;
    }
};
