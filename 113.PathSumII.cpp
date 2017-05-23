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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<TreeNode*> path;
        TreeNode *preNode = root;
        int curSum = 0;
        while (!path.empty() || root != nullptr) {
            while (root != nullptr) {
                path.push_back(root);
                preNode = root;
                curSum += root->val;
                root = root->left;
            }
            if (path.back()->right == nullptr && sum == curSum) {
                vector<int> numArr;
                for (auto node : path)
                    numArr.push_back(node->val);
                res.push_back(numArr);
            }
            while (!path.empty() && (path.back()->right == nullptr || path.back()->right == preNode)) {
                curSum -= path.back()->val;
                preNode = path.back();
                path.pop_back();
            }
            if (!path.empty())
                root = path.back()->right;
        }
        return res;
    }
};
