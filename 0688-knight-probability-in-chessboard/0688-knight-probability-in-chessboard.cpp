class Solution {
public:

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1, vector<vector<double>> (n+1, vector<double> (n+1,-1)));

        double onBoard=moveKnight(n,k,row,column,dp);

        return onBoard/pow(8,k);
    }

    double moveKnight(int n, int k, int i, int j, vector<vector<vector<double>>>& dp)
    {   

        if(i<0 || j<0 || i>=n || j>=n)
        {
            return 0;
        }

        if(k==0)
        {   
            return 1;
        }
        
        if(dp[k][i][j]!=-1)
            return dp[k][i][j];

        double ans=0;

        ans+=moveKnight(n,k-1,i-2,j+1,dp);
        ans+=moveKnight(n,k-1,i-1,j+2,dp);

        ans+=moveKnight(n,k-1,i+1,j+2,dp);
        ans+=moveKnight(n,k-1,i+2,j+1,dp);

        ans+=moveKnight(n,k-1,i+2,j-1,dp);
        ans+=moveKnight(n,k-1,i+1,j-2,dp);

        ans+=moveKnight(n,k-1,i-1,j-2,dp);
        ans+=moveKnight(n,k-1,i-2,j-1,dp);

        dp[k][i][j]=ans;

        return ans;
    }
};