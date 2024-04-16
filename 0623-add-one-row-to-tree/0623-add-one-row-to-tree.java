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
    void addRow(TreeNode curr, TreeNode prev, int val, int depth, boolean flag)
    {
        if(--depth == 0)
        {
            if(curr == null)
            {
                if(flag)
                    prev.left = new TreeNode(val);
                else
                    prev.right = new TreeNode(val);
            }
            else
            {
                TreeNode temp = new TreeNode(val);
                if(flag)
                {
                    prev.left = temp;
                    temp.left = curr;
                }
                else
                {
                    prev.right = temp;
                    temp.right = curr;
                }

            }

            return;
        }

        if(curr != null)
        {
            addRow(curr.left, curr, val, depth, true);
            addRow(curr.right, curr, val, depth, false);
        }
    }
    
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode answer = new TreeNode(val, root, null);
            return answer;
        }

        addRow(root, null, val, depth, false);
        return root;
    }
}