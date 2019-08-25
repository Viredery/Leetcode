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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int left, int right) {
        if (left > right)
            return {nullptr};
        if (left == right) 
            return {new TreeNode(left)};
        
        vector<TreeNode*> res;
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> leftVec = generateTrees(left, i-1);
            vector<TreeNode*> rightVec = generateTrees(i+1, right);
            for (auto lchild : leftVec)
                for (auto rchild : rightVec) {
                    TreeNode* node = new TreeNode(i);
                    node->left = lchild;
                    node->right = rchild;
                    res.push_back(node);
                }
        }
        return move(res);      
    }
};
