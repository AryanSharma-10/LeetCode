class Solution {
    static List<List<Integer>> result;
    int[] visited;
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int m = graph.length;
        visited = new int[m];
        result = new ArrayList<>();
        List<Integer> comb = new ArrayList<>();
        comb.add(0);
        allPaths(graph, comb, 0, m);
        return result;
    }

    public static void allPaths(int[][] graph, List<Integer> comb, int i, int m)
    {
        if(i == m-1)
        {
            comb.add(i);
            result.add(comb);
        }

        for(int j=0;j<graph[i].length;j++)
        {   
            List temp = new ArrayList<>(comb);
            temp.add(graph[i][j]);
            allPaths(graph, temp, graph[i][j], m);
            temp.remove(temp.size()-1);
        }
    }
}