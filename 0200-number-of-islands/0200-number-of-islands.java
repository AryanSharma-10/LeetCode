class Solution {
    public int numIslands(char[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int count=0;

        int[][] visited = new int[m][n];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    count++;
                    findIslands(grid, visited, i, j, m, n);
                }

            }
        }

        return count;
    }

    public static void findIslands(char[][] grid, int[][] visited, int i, int j, int m, int n)
    {
        if(grid[i][j]!='1')
            return;
        
        visited[i][j]=1;
        
        if(i>0 && visited[i-1][j]==0)
            findIslands(grid, visited, i-1, j, m, n);
        
        if(j+1<n && visited[i][j+1]==0)
            findIslands(grid, visited, i, j+1, m, n);
        
        if(i+1<m && visited[i+1][j]==0)
            findIslands(grid, visited, i+1, j, m, n);
        
        if(j>0 && visited[i][j-1]==0)
            findIslands(grid, visited, i, j-1, m, n);
    }
}