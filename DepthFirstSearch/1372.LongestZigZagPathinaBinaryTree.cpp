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
    int longestZigZag(TreeNode* root) {
        int longest_length = 0;
        longestZigZag(root, true, &longest_length);
        return longest_length - 1;
    }
private:
    int longestZigZag(const TreeNode* root, bool from_left, int* longest_length) {
        if (!root) {
            return 0;
        }
        const int left_length = longestZigZag(root->left, true, longest_length);
        const int right_length = longestZigZag(root->right, false, longest_length);
        *longest_length = std::max(*longest_length, std::max(left_length, right_length) + 1);
        return from_left ? right_length + 1 : left_length + 1;
    }
};
