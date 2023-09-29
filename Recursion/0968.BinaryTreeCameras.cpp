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
    int minCameraCover(TreeNode* root) {
        int min_cover = 0;
        const Mode root_mode = dfs(root, &min_cover);
        return root_mode == Mode::kChildren ? min_cover + 1 : min_cover;
    }
private:
    enum class Mode {
        kNone = 0,
        kChildren = 1,
        kCamera = 2,
        kUnsupported = 10000,
    };

    Mode dfs(const TreeNode* root, int* min_cover) {
        if (!root) {
            return Mode::kNone;
        }
        const Mode left_mode = dfs(root->left, min_cover);
        const Mode right_mode = dfs(root->right, min_cover);
        if (left_mode == Mode::kNone && right_mode == Mode::kNone) {
            return Mode::kChildren;
        }
        if (left_mode == Mode::kChildren || right_mode == Mode::kChildren) {
            ++(*min_cover);
            return Mode::kCamera;
        }
        if (left_mode == Mode::kCamera || right_mode == Mode::kCamera) {
            return Mode::kNone;
        }
        return Mode::kUnsupported;
    }
};
