/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            path.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* root = path.top();
        int val = root->val;
        path.pop();
        root = root->right;
        while (root) {
            path.push(root);
            root = root->left;
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !path.empty();
    }
private:
    stack<TreeNode*> path;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
