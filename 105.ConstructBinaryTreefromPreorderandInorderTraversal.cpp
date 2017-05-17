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
        TreeNode *root = nullptr;
        buildTree(root, preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }
private:
    void buildTree(TreeNode* &root, vector<int>& preorder, int preleft, int preright,
                   vector<int>& inorder, int inleft, int inright) {
        if (inleft > inright) return;
        root = new TreeNode(preorder[preleft]);
        int inmid = searchVal(inorder, inleft, inright, preorder[preleft]);
        buildTree(root->left, preorder, preleft+1, preleft+inmid-inleft, inorder, inleft, inmid-1);
        buildTree(root->right, preorder, preleft+inmid-inleft+1, preright, inorder, inmid+1, inright);
    }
    int searchVal(vector<int>& vec, int l, int r, int val) {
        for(int i = l; i <= r; i++)
            if (vec[i] == val)
                return i;
        return -1;
    }
};
