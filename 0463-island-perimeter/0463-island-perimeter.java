class Solution {
    class Pair{
        int x;
        int y;

        Pair(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    public int islandPerimeter(int[][] grid) {
        int i = 0;
        int j = 0;
        int m = grid.length;
        int n = grid[0].length;
        boolean [][] vis = new boolean[m][n];
        boolean flag = false;
        int perimeter = 0;
        for(int x = 0; x < m ; x++)
        {
            for(int y = 0; y < n ; y++)
            {   
                if(grid[x][y] == 1)
                {
                    flag = true;
                    i = x;
                    j = y;
                    break;
                }
            }

            if(flag)
                break;
        }

        Deque<Pair> q = new LinkedList<>();
        vis[i][j] = true;
        q.add(new Pair(i, j));

        while(!q.isEmpty())
        {
            Pair island = q.poll();
            i = island.x;
            j = island.y;

            int surr = 0;

            if(i - 1 >= 0 && grid[i - 1][j] == 1)
            {
                if(!vis[i - 1][j])
                {
                    vis[i - 1][j] = true;
                    q.add(new Pair(i - 1, j));
                }
                surr++;
            }
            if(j + 1 < n && grid[i][j + 1] == 1)
            {
                if(!vis[i][j + 1])
                {
                    vis[i][j + 1] = true;
                    q.add(new Pair(i, j + 1));
                }
                surr++;
            }
            if(i + 1 < m && grid[i + 1][j] == 1)
            {
                if(!vis[i + 1][j])
                {
                    vis[i + 1][j] = true;
                    q.add(new Pair(i + 1, j));
                }
                surr++;
            }
            if(j - 1 >= 0 && grid[i][j - 1] == 1)
            {
                if(!vis[i][j - 1])
                {
                    vis[i][j - 1] = true;
                    q.add(new Pair(i, j - 1));
                }
                surr++;
            }

            perimeter += 4 - surr;
        }

        return perimeter;
    }
}