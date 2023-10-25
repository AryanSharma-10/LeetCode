class Pair {
    int x;
    int y;

    Pair(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public int minimumEffortPath(int[][] heights) {
        int m = heights.length;
        int n = heights[0].length;

        int [][] dist = new int [m][n];
        for(int i = 0 ; i < m ; i++)
        {
            Arrays.fill(dist[i], (int) 1e9 );
        }

        dist[0][0] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>( ( p1, p2 ) -> dist[p1.x][p1.y] - dist[p2.x][p2.y] );
        pq.add(new Pair(0, 0));

        int [] dr = { -1, 0, 1, 0}; 
        int [] dc = { 0, 1, 0, -1};

        while(!pq.isEmpty())
        {   
            int row = pq.peek().x;
            int col = pq.remove().y;

            // System.out.println("Exploring: " + heights[row][col]);

            for(int i = 0 ; i < 4 ; i++)
            {
                int adjRow = row + dr[i];
                int adjCol = col + dc[i];

                if(adjRow >= 0 && adjCol >= 0 && adjRow < m && adjCol < n)
                {   
                    int newDist = Math.max( dist[row][col], Math.abs( heights[row][col] - heights[adjRow][adjCol] ) );
                    if( dist[adjRow][adjCol] >  newDist)
                    {
                        dist[adjRow][adjCol] = newDist;

                        // System.out.println("Adding: " + heights[adjRow][adjCol] + " ("+ dist[adjRow][adjCol]+") ");

                        pq.add(new Pair(adjRow, adjCol));
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
}