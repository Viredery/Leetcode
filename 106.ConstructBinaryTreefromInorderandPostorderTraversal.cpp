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
        TreeNode *root = nullptr;
        buildTree(root, postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
        return root;        
    }
private:
    void buildTree(TreeNode* &root, vector<int>& postorder, int postleft, int postright,
                   vector<int>& inorder, int inleft, int inright) {
        if (inleft > inright) return;
        root = new TreeNode(postorder[postright]);
        int inmid = searchVal(inorder, inleft, inright, postorder[postright]);
        buildTree(root->left, postorder, postleft, postleft+inmid-inleft-1, inorder, inleft, inmid-1);
        buildTree(root->right, postorder, postleft+inmid-inleft, postright-1, inorder, inmid+1, inright);
    }
    int searchVal(vector<int>& vec, int l, int r, int val) {
        for(int i = l; i <= r; i++)
            if (vec[i] == val)
                return i;
        return -1;
    }
};
