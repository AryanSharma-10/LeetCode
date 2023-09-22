class Solution {
    public static boolean dfs(ArrayList<ArrayList<Integer>> adj, int [] visited, int [] path, int node)
    {
        visited[node] = 1;
        path[node] = 1;

        for(int adjNode : adj.get(node))
        {
            if(visited[adjNode] == 0)
            {
                if(dfs(adj, visited, path, adjNode))
                    return true;
            }

            else if(path[adjNode] == 1)
            {
                return true;
            }
        }

        path[node] = 0;
        return false;
    }
    
    public boolean canFinish(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        int [] visited = new int[V];
        int [] path = new int[V];

        for(int i = 0; i < V ; i++)
        {
            adj.add(new ArrayList<Integer>());
        }

        for(int [] arr : edges)
        {
            adj.get(arr[1]).add(arr[0]);
        }

        for(int i = 0 ; i < V ; i++)
        {
            if(visited[i] == 0)
                if(dfs(adj, visited, path, i))
                    return false;
        }
        return true;
    }
}