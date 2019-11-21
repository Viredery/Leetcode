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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder,
                 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                   int pl, int pr, int il, int ir) {
        if (pl > pr)
            return nullptr;
        int val = preorder[pl];
        TreeNode* root = new TreeNode(val);
        int pos = find(inorder, il, ir, val);
        root->left = buildTree(preorder, inorder,
                               pl+1, pl+pos-il,
                               il, pos-1);
        root->right = buildTree(preorder, inorder,
                                pl+1+pos-il, pr,
                                pos+1, ir);
        return root;
    }

    int find(vector<int>& inorder, int il, int ir, int val) {
        for(int i = il; i <= ir; i++)
            if (inorder[i] == val)
                return i;
        return -1;
    }
};
