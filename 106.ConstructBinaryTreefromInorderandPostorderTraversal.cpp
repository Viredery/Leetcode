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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 
                         0, inorder.size(), 0, 
                         postorder.size());
    }
private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                        int instart, int inend, int poststart, int postend) {
        if (instart >= inend)
            return nullptr;
        int val = postorder[postend-1];
        TreeNode* root = new TreeNode(val);
        int pos = find(inorder, instart, inend, val);
        root->left = buildTree(inorder, postorder, 
                               instart, pos, 
                               poststart, poststart+pos-instart);
        root->right = buildTree(inorder, postorder, 
                                pos+1, inend, 
                                poststart+pos-instart, postend-1);
        return root;
    }
    
    int find(vector<int>& inorder, int instart, int inend, int val) {
        for (int i = instart; i != inend; i++)
            if (inorder[i] == val)
                return i;
    }

};