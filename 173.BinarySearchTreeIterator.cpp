/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !trace.empty();
    }

    /** @return the next smallest number */
    int next() {
        int res = trace.back()->val;
        TreeNode* node = trace.back()->right;
        trace.pop_back();
        pushAll(node);
        return res;
    }
private:
    vector<TreeNode*> trace;
    void pushAll(TreeNode* node) {
        while (node) {
            trace.push_back(node);
            node = node->left;
        }        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */