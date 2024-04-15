/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int treeSum(TreeNode root, int num)
    {
        if(root == null)
            return 0;

        if(root.left == null && root.right == null)
            return num * 10 + root.val;

        num = num * 10 + root.val;

        return treeSum(root.left, num) + treeSum(root.right, num);
    }

    public int sumNumbers(TreeNode root) {
        return treeSum(root, 0);   
    }
}