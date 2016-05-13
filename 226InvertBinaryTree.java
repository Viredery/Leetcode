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
    public TreeNode invertTree(TreeNode root) {
        if (root == null)
            return root;
        if (root.left != null && root.right != null) {
            TreeNode tmp = root.left;
            root.left = root.right;
            root.right = tmp;
            invertTree(root.left);
            invertTree(root.right);
        } else if (root.left != null) {
            root.right = root.left;
            root.left = null;
            invertTree(root.right);
        } else if (root.right != null) {
            root.left = root.right;
            root.right = null;
            invertTree(root.left);
        }
        return root;
    }
}