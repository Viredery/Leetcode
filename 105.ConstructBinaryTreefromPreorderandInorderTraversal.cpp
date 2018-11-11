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
                         0, preorder.size(), 0, inorder.size());
    }
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                   int prestart, int preend, int instart, int inend) {
        if (prestart >= preend)
            return nullptr;
        int val = preorder[prestart];
        TreeNode* root = new TreeNode(val);
        int pos = find(inorder, instart, inend, val);
        root->left = buildTree(preorder, inorder, 
                               prestart+1, prestart+1+pos-instart,
                               instart, pos);
        root->right = buildTree(preorder, inorder, 
                                prestart+1+pos-instart, preend,
                                pos+1, inend);
        return root;
    }
    
    int find(vector<int>& inorder, int instart, int inend, int val) {
        for(int i = instart; i != inend; i++)
            if (inorder[i] == val)
                return i;
    }
};