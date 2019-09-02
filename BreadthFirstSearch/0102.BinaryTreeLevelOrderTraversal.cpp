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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderNum;
        queue<TreeNode*> visitedNodes;
        if (!root)
            return levelOrderNum;
        visitedNodes.push(root);
        while (!visitedNodes.empty()) {
            int amount = visitedNodes.size();
            vector<int> orderNum;
            for (int _ = 0; _ != amount; _++) {
                auto node = visitedNodes.front();
                visitedNodes.pop();
                orderNum.push_back(node->val);
                if (node->left) 
                    visitedNodes.push(node->left);
                if (node->right)
                    visitedNodes.push(node->right);
            }
            levelOrderNum.push_back(std::move(orderNum));
        }
        return levelOrderNum;
    }
};
