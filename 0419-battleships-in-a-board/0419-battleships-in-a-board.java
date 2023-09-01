class Solution {
    public int countBattleships(char[][] board) {
        int m=board.length;
        int n=board[0].length;
        int count=0;

        int[][] visited = new int[m][n];

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='X' && visited[i][j]==0)
                {
                    count++;
                    markShips(board, visited, m, n, i, j);
                    
                }
            }
        }

        return count;
    }

    public static void markShips(char[][] board, int[][] visited, int m, int n, int i, int j)
    {
        int row=0;
        int col=0;

        int x=i;
        int y=j;

        while(i<m && board[i][j]=='X')
        {
            col++;
            i++;
        }

        int tempi=i;
        i=x;

        while(j<n && board[i][j]=='X')
        {
            row++;
            j++;
        }

        int tempj=j;
        j=y;

        if(col>row)
        {   

            while(x<tempi)
            {
                visited[x++][y]=1;
            }
        }
        else
        {
            while(y<tempj)
            {  
                visited[x][y++]=1;
            }
        }
    }
}