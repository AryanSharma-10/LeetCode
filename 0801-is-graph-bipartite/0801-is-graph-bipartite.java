class Solution {
    public static boolean check(int[][] graph, int [] col, int startNode)
    {
        Queue <Integer> queue = new LinkedList<>();
        queue.add(startNode);
        col[startNode] = 1;

        while(!queue.isEmpty())
        {   
            int node = queue.peek();
            int color = 1;

            if(col[node] == 1)
                color = 2;
            
            queue.remove();

            for(int adjNode : graph[node])
            {   

                if(col[adjNode] == 0)
                {   
                    col[adjNode] = color;
                    queue.add(adjNode);
                }

                else
                {
                    if(col[adjNode] != color)
                        return false;
                }
            }
        }

        return true;
    }

    public boolean isBipartite(int[][] graph) {
        int m = graph.length;
        int [] col = new int [m];

        for(int i = 0 ; i < m ; i++)
        {   
            if(col[i] == 0)
            {
                boolean flag = check(graph, col, i);
                if(!flag)
                    return false;
            }
        }
        return true;
    }
}