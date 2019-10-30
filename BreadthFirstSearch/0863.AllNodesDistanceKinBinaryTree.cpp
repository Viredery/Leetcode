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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*> path;
        getPath(root, target, path);
        int n = path.size();
        vector<int> res;
        getDistanceK(path.back(), K, res);
        if (K == 0)
            return res;
        for (int i = 1; i != path.size(); i++) {
            if (i == K) {
                res.push_back(path[n-1-i]->val);
                return res;
            }
            if (path[n-1-i]->right && path[n-1-i]->left == path[n-i])
                getDistanceK(path[n-1-i]->right, K-1-i, res);
            else if (path[n-1-i]->left && path[n-1-i]->right == path[n-i])
                getDistanceK(path[n-1-i]->left, K-1-i, res);
        }
        return res;
    }
private:
    void getDistanceK(TreeNode* root, int K, vector<int>& res) {
        if (!root)
            return;
        if (K == 0) {
            res.push_back(root->val);
            return;
        }
        getDistanceK(root->left, K-1, res);
        getDistanceK(root->right, K-1, res);
    }
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root)
            return false;
        path.push_back(root);
        if (root == target)
            return true;
        if (getPath(root->left, target, path))
            return true;
        if (getPath(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }
};
