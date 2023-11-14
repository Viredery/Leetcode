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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lcaDeepestLeaves(root, 0).node;
    }
private:
    struct NodeWithDepth {
        TreeNode* node = nullptr;
        int depth = 0;
    };

    NodeWithDepth lcaDeepestLeaves(TreeNode* root, int depth) {
        if (!root) {
            return NodeWithDepth{root, depth};
        }
        NodeWithDepth left = lcaDeepestLeaves(root->left, depth + 1);
        NodeWithDepth right = lcaDeepestLeaves(root->right, depth + 1);
        if (left.depth == right.depth) {
            return NodeWithDepth{root, left.depth + 1};
        }
        return left.depth < right.depth 
                   ? NodeWithDepth{right.node, right.depth + 1}
                   : NodeWithDepth{left.node, left.depth + 1};
    }
};
