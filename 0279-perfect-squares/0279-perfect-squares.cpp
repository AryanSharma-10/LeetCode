class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return perfectSquare(n,dp);
    }

    int perfectSquare(int n, vector<int>& dp)
    {   
        if(n==0)
            return 0;

        if(dp[n]!=-1)
            return dp[n];

        int minNum=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            int num=1+perfectSquare(n-(i*i), dp);
            minNum=min(minNum,num);
        }

        return dp[n]=minNum;
    }
};