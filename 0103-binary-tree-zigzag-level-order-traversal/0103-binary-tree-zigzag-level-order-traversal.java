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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> zigLevelOrder = new ArrayList<>();
        if(root == null)
            return zigLevelOrder;
            
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        boolean flag = true;

        while(!q.isEmpty())
        {   
            List<Integer> temp = new LinkedList<>();
            int size = q.size();
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode curr = q.poll();
                temp.add(curr.val);

                if(curr.left != null)
                    q.add(curr.left);

                if(curr.right != null)
                    q.add(curr.right);
            }

            if(flag)
            {
                flag = false;
                zigLevelOrder.add(temp);
            }
            else
            {
                flag = true;
                Collections.reverse(temp);
                zigLevelOrder.add(temp);
            }
        }

        return zigLevelOrder;
    }
}