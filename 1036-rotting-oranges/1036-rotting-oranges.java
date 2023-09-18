class Pair {
  int row;
  int col;
  int time;

  Pair(int row, int col, int time)
  {
    this.row = row;
    this.col = col;
    this.time = time;
  }

}

class Solution {
    public int orangesRotting(int[][] grid) {
      int m = grid.length;
      int n = grid[0].length; 
      int [][] visited = new int [m][n];

      int count = 0;

      Queue<Pair> queue = new LinkedList<>();

      for(int i = 0 ; i < m ; i++)
      {
        for(int j = 0 ; j < n ; j++)
        {
          if(grid[i][j] == 2)
          {
            queue.add(new Pair(i , j, 0));
            visited[i][j] = 1;
          }
          
          if(grid[i][j] != 0)
            count++;
        }
      }

      int maxTime = 0;
      int cnt = 0;

      while(!queue.isEmpty())
      {

        int row = queue.peek().row;
        int col = queue.peek().col;
        int time = queue.peek().time;

        maxTime = Math.max(maxTime, time);

        if(row > 0 && visited[row - 1][col] == 0 && grid[row - 1][col] == 1)
        {
          queue.add(new Pair(row - 1, col, time+1));
          visited[row - 1][col] = 1;
        }

        if(col + 1 < n && visited[row][col + 1] == 0 && grid[row][col + 1] == 1)
        {
          queue.add(new Pair(row, col + 1, time+1));
          visited[row][col + 1] = 1;
        }

        if(row + 1 < m && visited[row + 1][col] == 0 && grid[row + 1][col] == 1)
        {
          queue.add(new Pair(row + 1, col, time+1));
          visited[row + 1][col] = 1;
        }

        if(col > 0 && visited[row][col - 1] == 0 && grid[row][col - 1] == 1)
        {
          queue.add(new Pair(row, col - 1, time+1));
          visited[row][col - 1] = 1;
        }
        cnt++;
        queue.poll();
      }

      if(cnt != count)
        return -1;
        
      return maxTime;
    }
}