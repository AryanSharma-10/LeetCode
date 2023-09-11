class Solution {
    static int count = 0;

    public int findCircleNum(int[][] graph) {
        int len = graph.length;
        count = 0;
        boolean [] visited = new boolean[len];

        for(int i = 0; i < len ; i++)
        {
            if(!visited[i])
            {
                count++;
                findCities(graph, i, visited);
            }
        }

        return count;
    }

    public static void findCities(int[][] graph, int node, boolean [] visited)
    {   
        visited[node] = true;
        int len = graph[node].length;
        for(int i = 0 ; i < len ; i++)
        {
            if(graph[node][i] == 1 && !visited[i])
            {
                visited[i] = true; 
                findCities(graph, i, visited);
            }
        }
    }
}