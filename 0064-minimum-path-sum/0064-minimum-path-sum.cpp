class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1, vector<int> (grid[0].size()+1,-1));
        return minCost(grid,dp,0,0);
    }

    int minCost(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j)
    {   
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int path=INT_MAX;

        if(j+1<grid[0].size())
            path=minCost(grid,dp,i,j+1);

        if(i+1<grid.size())
            path=min(path,minCost(grid,dp,i+1,j));
        
        path+=grid[i][j];

        dp[i][j]=path;

        return dp[i][j];
    
    }
};