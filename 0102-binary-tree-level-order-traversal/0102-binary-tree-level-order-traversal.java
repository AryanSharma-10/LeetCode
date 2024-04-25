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
    void depthTraversal(TreeNode root, List<List<Integer>> lvl, int depth)
    {
        if(root == null)
            return;
        
        if(lvl.size() <= depth)
        {
            List<Integer> temp = new ArrayList<>();
            temp.add(root.val);
            lvl.add(temp);
        }
        else
        {
            lvl.get(depth).add(root.val);
        }

        depthTraversal(root.left, lvl, depth + 1);
        depthTraversal(root.right, lvl, depth + 1);
    }
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> lvl = new ArrayList<>();
        depthTraversal(root, lvl, 0);

        return lvl;
    }
}