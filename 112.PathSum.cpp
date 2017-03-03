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
    bool hasPathSum(TreeNode* root, int sum) {
        stack<tuple<TreeNode*, int>> state;
        if (nullptr == root) return false;
        state.emplace(root, root->val);
        decltype(root) curPtr = root;
        while (!state.empty()) {
            while (nullptr != curPtr->left) {
                curPtr = curPtr->left;
                state.emplace(curPtr, get<1>(state.top()) + curPtr->val);
            }
            if (nullptr == curPtr->right) {
                if (sum == get<1>(state.top()))
                    return true;
                state.pop();
                while (!state.empty()) {
                    auto curState = state.top();
                    state.pop();
                    curPtr = get<0>(curState)->right;
                    if (nullptr != curPtr) {
                        state.emplace(curPtr, get<1>(curState) + curPtr->val);
                        break;
                    }
                }
            } else {
                auto curState = state.top();
                state.pop();
                curPtr = curPtr->right;
                state.emplace(curPtr, get<1>(curState) + curPtr->val);
            }
        }
        return false;
    }
};