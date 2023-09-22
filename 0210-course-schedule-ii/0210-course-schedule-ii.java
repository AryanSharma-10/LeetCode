class Solution {
    public int[] findOrder(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        int [] inDegree = new int [V];
        Queue <Integer> queue = new LinkedList<>();

        for(int i = 0 ; i < V ; i++)
        {
            adj.add(new ArrayList<Integer>());
        }

        for(int [] arr : edges)
        {   
            inDegree[arr[0]]++;
            adj.get(arr[1]).add(arr[0]);
        }

        for(ArrayList<Integer> arr : adj)
            System.out.println(arr);

        for(int i = 0 ; i < V ; i++)
        {
            if(inDegree[i] == 0)
                queue.add(i);
        }
        int [] res = new int[V];
        int i = 0;

        while(!queue.isEmpty())
        {
            int node = queue.remove();

            for(int adjNode : adj.get(node))
            {
                if(--inDegree[adjNode] == 0)
                    queue.add(adjNode);
            }
            res[i++] = node;
        }

        if(i!=V)
            return new int[0]; 

        return res;
    }
}