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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty() || preorder.size() != postorder.size()) {
            return nullptr;
        }
        const int size = postorder.size();
        std::unordered_map<int, int> post_indexes;
        for (int i = 0; i != postorder.size(); ++i) {
            post_indexes[postorder[i]] = i;
        }
        return Construct(post_indexes, preorder, 0, size - 1, postorder, 0, size - 1);
    }
private:
    TreeNode* Construct(const std::unordered_map<int, int>& post_indexes,
                        const std::vector<int>& preorder, int pre_left, int pre_right,
                        const std::vector<int>& postorder, int post_left, int post_right) {
        if (pre_left > pre_right) {
            return nullptr;
        }
        const int val = preorder[pre_left];
        TreeNode* root = new TreeNode(val);
        if (pre_left == pre_right) {
            return root;
        }
        const int post_idx = post_indexes.at(preorder[pre_left + 1]);
        const int left_size = post_idx - post_left;
        root->left = Construct(post_indexes, 
                               preorder, pre_left + 1, pre_left + 1 + left_size,
                               postorder, post_left, post_idx);
        root->right = Construct(post_indexes,
                                preorder, pre_left + 2 + left_size, pre_right,
                                postorder, post_idx + 1, post_right - 1);
        return root;
    }
};
