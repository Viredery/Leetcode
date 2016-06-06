/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) 
            return true;
        return isTwoNodeSymmetric(root, root);
    }
    private boolean isTwoNodeSymmetric(TreeNode first, TreeNode second) {
        return (first.val == second.val && 
                (first.left != null && second.right != null && isTwoNodeSymmetric(first.left, second.right) ||
                first.left == null && second.right == null) &&
                (first.right != null && second.left != null && isTwoNodeSymmetric(first.right, second.left) ||
                first.right == null && second.left == null)) ? true : false;
    }
}