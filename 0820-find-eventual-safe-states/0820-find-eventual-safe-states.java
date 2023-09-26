// class Solution {
//     public static boolean dfs(int[][] graph, int[] path, int[] vis, int node, int[] safe)
//     {
//         System.out.println(node);
//         vis[node] = 1;
//         path[node] = 1;
//         safe[node] = 0;

//         for(int adjNode : graph[node])
//         {
//             if(vis[adjNode] == 0)
//             {
//                 if(dfs(graph, path, vis, adjNode, safe))
//                     return true;
//             }

//             else if(path[adjNode] == 1)
//             {
//                 return true;
//             }
//         }

//         safe[node] = 1;
//         path[node] = 0;

//         return false;
//     }

//     public List<Integer> eventualSafeNodes(int[][] graph) 
//     {
//         int m = graph.length;
//         int [] path = new int[m];
//         int [] vis = new int[m];
//         int [] safe = new int[m];
//         List<Integer> result = new ArrayList<>();

//         for(int i = 0 ; i < m ; i++)
//         {   
//             if(vis[i] == 0)
//                 dfs(graph, path, vis, i, safe);
//         }

//         for(int i = 0 ; i < m ; i++)
//         {
//             if(safe[i] == 1)
//                 result.add(i);
//         }

//         return result;
//     }
// }

class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) 
    {   
        int V = graph.length;
        List<List<Integer>> adj = new ArrayList<>();

        for(int  i = 0 ; i < V ; i++)
            adj.add(new ArrayList<Integer>() );
        
        int [] inDegree = new int[V];

        for(int i = 0 ; i < V ; i++)
        {
            for(int adjNode : graph[i])
            {
                adj.get(adjNode).add(i);
                inDegree[i]++;
            }
        }

        Queue<Integer> queue = new LinkedList<>();

        for(int i = 0 ; i < V ; i++)
        {
            if(inDegree[i] == 0)
                queue.add(i);
        }

        List<Integer> result = new ArrayList<>();

        while(!queue.isEmpty())
        {
            int node = queue.remove();

            for(int adjNode : adj.get(node))
            {
                if(--inDegree[adjNode] == 0)
                    queue.add(adjNode);
            }

            result.add(node);
        }

        Collections.sort(result);

        return result;
    }
}