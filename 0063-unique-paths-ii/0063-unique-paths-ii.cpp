class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size()+1,vector<int> (obstacleGrid[0].size()+1, -1));
        return diffPath(obstacleGrid, dp, 0, 0);
    }

    int diffPath(vector<vector<int>>& og, vector<vector<int>>&dp, int i, int j)
    {   
        if(og[i][j]==1)
            return 0;

        if(i==og.size()-1 && j==og[0].size()-1 && og[i][j]!=1)
        {
            return 1;
        }


        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int path=0;

        if(i+1<og.size() && og[i+1][j]!=1)
        {  
            path+=diffPath(og,dp,i+1,j);
        }

        if(j+1<og[0].size() && og[i][j+1]!=1)
        {
            path+=diffPath(og,dp,i,j+1);
        }

        dp[i][j]=path;

        return path;
    }
};