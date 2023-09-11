class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;

        int m = image.length;
        int n = image[0].length;
        int[][] result = new int[m][n];
        boolean[][] visited = new boolean[m][n];
        int oldColour = image[sr][sc];

        fill(image, result, visited, sr, sc, color, oldColour, m, n);
          
        return image;
    }

    public static void fill(int[][] image, int[][] result, boolean[][] visited, int sr, int sc, int newColour, int oldColour, int m, int n)
    {   
        image[sr][sc] = newColour;

        if(sr>0 && !visited[sr-1][sc] && image[sr-1][sc]==oldColour)
        {
            visited[sr-1][sc] = true;
            fill(image, result, visited, sr-1, sc, newColour, oldColour, m, n);
        }

        if(sc+1<n && !visited[sr][sc+1] && image[sr][sc+1]==oldColour)
        {
            visited[sr][sc+1] = true;
            fill(image, result, visited, sr, sc+1, newColour, oldColour, m, n);
        }

        if(sr+1<m && !visited[sr+1][sc] && image[sr+1][sc]==oldColour)
        {
            visited[sr+1][sc] = true;
            fill(image, result, visited, sr+1, sc, newColour, oldColour, m, n);
        }

        if(sc>0 && !visited[sr][sc-1] && image[sr][sc-1]==oldColour)
        {
            visited[sr][sc-1] = true;
            fill(image, result, visited, sr, sc-1, newColour, oldColour, m, n);
        }
    }
}