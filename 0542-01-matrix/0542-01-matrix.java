class Pair {
    int row;
    int col;
    int step;

    Pair(int row, int col, int step)
    {
        this.row = row;
        this.col = col;
        this.step = step;
    }
}

class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m=mat.length;
        int n=mat[0].length;
        int [][] dist = new int [m][n];
        int [][] vis = new int[m][n];
        
        Queue <Pair> queue = new LinkedList <Pair>();

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {   
                if(mat[i][j] == 0)
                {   
                    queue.add(new Pair(i , j, 0));
                    vis[i][j] = 1;
                }
            }

        }
        
        while(!queue.isEmpty())
        {
            int row = queue.peek().row;
            int col = queue.peek().col;
            int step = queue.peek().step;

            queue.remove();

            dist[row][col] = step;
            
            if(row > 0 && vis[row - 1][col] == 0)
            {
                vis[row - 1][col] = 1;
                queue.add(new Pair(row -1, col, step+1));
            }

            if(col + 1 < n && vis[row][col+1] == 0)
            {
                vis[row][col+1] = 1;
                queue.add(new Pair(row, col+1, step+1));
            }

            if(row + 1 < m && vis[row + 1][col] == 0)
            {
                vis[row + 1][col] = 1;
                queue.add(new Pair(row + 1, col, step+1));
            }

            if(col > 0 && vis[row][col - 1] == 0)
            {
                vis[row][col - 1] = 1;
                queue.add(new Pair(row, col - 1, step+1));
            }
            
        }

        return dist;
    }

    // public static int findZero(int[][] mat, int m, int n, int i, int j)
    // {   
    //     System.out.println("Inside: "+i+" "+j);

    //     if(mat[i][j]==0)
    //         return 0;
        
    //     if(sol[i][j]!=0)
    //     {
    //         System.out.println("Taking value from sol: "+sol[i][j]);
    //         return sol[i][j];
    //     }

    //     vis[i][j]=1;

    //     int subAns=Integer.MAX_VALUE;
        


    //     sol[i][j]=subAns;

    //     vis[i][j]=0;

    //     return sol[i][j];
        
    // }
}