class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1, -1));
        return diffPath(dp, m, n, 0, 0);
    }

    int diffPath(vector<vector<int>>&dp, int m, int n, int i, int j)
    {
        if(i==m-1 && j==n-1)
        {
            return 1;
        }


        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int path=0;

        if(i+1<m)
        {  
            path+=diffPath(dp,m,n,i+1,j);
        }

        if(j+1<n)
        {
            path+=diffPath(dp,m,n,i,j+1);
        }

        dp[i][j]=path;

        return path;
    }
};