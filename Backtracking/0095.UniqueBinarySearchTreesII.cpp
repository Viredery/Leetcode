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
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int left, int right) {
        if (left > right) {
            return {nullptr};
        }
        if (left == right) {
            return {new TreeNode(left)};
        }
        std::vector<TreeNode*> trees;
        for (int i = left; i <= right; ++i) {
            std::vector<TreeNode*> left_trees = generateTrees(left, i - 1);
            std::vector<TreeNode*> right_trees = generateTrees(i + 1, right);
            for (auto* l : left_trees) {
                for (auto* r : right_trees) {
                    trees.push_back(new TreeNode(i, l, r));
                }
            }
        }
        return trees;
    }
};
