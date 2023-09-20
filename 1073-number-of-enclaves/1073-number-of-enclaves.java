class Solution {
    public static void dfs(int[][] board, int [][] vis, int row, int col, int m, int n){
        if(row > 0 && board[row - 1][col] == 1 && vis[row - 1][col] == 0)
        {
            vis[row - 1][col] = 1;
            dfs(board, vis, row - 1, col, m, n);
        }

        if(col + 1 < n && board[row][col + 1] == 1 && vis[row][col+1] == 0)
        {
            vis[row][col+1] = 1;
            dfs(board, vis, row, col + 1, m, n);
        }

        if(row + 1 < m && board[row + 1][col] == 1 && vis[row + 1][col] == 0)
        {
            vis[row + 1][col] = 1;
            dfs(board, vis, row + 1, col, m, n);
        }

        if(col > 0 && board[row][col - 1] == 1 && vis[row][col - 1] == 0)
        {
            vis[row][col - 1] = 1;
            dfs(board, vis, row, col - 1, m, n);
        }
    }
    
    public int numEnclaves(int[][] board) {
        int m = board.length;
        int n = board[0].length;

        int [][] visited = new int[m][n];

        int i = -1;
        int j = 0;

        while(++i < m)
        {
            if(visited[i][j] == 0 && board[i][j] == 1)
            {
                visited[i][j] = 1;
                dfs(board, visited, i, j, m, n);
            }
        }

        i = 0;
        j = -1;

        while(++j < n)
        {
            if(visited[i][j] == 0 && board[i][j] == 1)
            {
                visited[i][j] = 1;
                dfs(board, visited, i, j, m, n);
            }
        }

        i = -1;
        j = n - 1;

        while(++i < m)
        {
            if(visited[i][j] == 0 && board[i][j] == 1)
            {
                visited[i][j] = 1;
                dfs(board, visited, i, j, m, n);
            }
        }

        i = m - 1;
        j = -1;

        while(++j < n)
        {
            if(visited[i][j] == 0 && board[i][j] == 1)
            {
                visited[i][j] = 1;
                dfs(board, visited, i, j, m, n);
            }
        }

        int count = 0;

        for(i = 0 ; i < m ; i++)
        {   
            for(j = 0 ; j <n ; j++)
            {
                if(visited[i][j] == 0 && board[i][j] == 1)
                    count++;
                
            }
        }

        return count;
    }
}