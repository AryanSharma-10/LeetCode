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
class Pair {
    TreeNode node;
    int time;

    Pair(TreeNode node, int time){
        this.node = node;
        this.time = time;
    }
}
class Solution {
    public int amountOfTime(TreeNode root, int start) {
        HashMap<TreeNode, TreeNode> parent = new HashMap<>();
        HashMap<Integer, Boolean> visited = new HashMap<>();

        Queue<TreeNode> q = new LinkedList<>();
        TreeNode entry = null;

        q.add(root);
        while(!q.isEmpty())
        {
            TreeNode curr = q.poll();
            if(curr.val == start)
                entry = curr;

            if(curr.left != null)
            {
                parent.put(curr.left, curr);
                q.add(curr.left);
            }
            if(curr.right != null)
            {
                parent.put(curr.right, curr);
                q.add(curr.right);
            }
        }

        Queue<Pair> Q = new LinkedList<>();
        int maxTime = 0;
        Q.add(new Pair(entry, 0));
        while(!Q.isEmpty())
        {
            Pair p = Q.poll();
            TreeNode curr = p.node;
            int time = p.time;

            visited.put(curr.val, true);
            maxTime = Math.max(time, maxTime);

            if(curr.left != null && visited.get(curr.left.val) == null)
                Q.add(new Pair(curr.left, time + 1));
            if(curr.right != null && visited.get(curr.right.val) == null)
                Q.add(new Pair(curr.right, time + 1));
            if(parent.get(curr) != null && visited.get(parent.get(curr).val) == null)
                Q.add(new Pair(parent.get(curr), time + 1));
        }

        return maxTime;
    }
}