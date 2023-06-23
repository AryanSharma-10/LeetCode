class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> dp(n+1,-1);
        return climb(n, dp);
    }

    int climb(int n, vector<int> &dp)
    {   
        if(n<0)
            return 0;

        if(dp[n]!=-1)
        {
            // cout<<"Taking value of "<<n<<" from dp"<<endl;
            return dp[n];
        }

        if(n==0)
            return 1;
        
        int steps=0;

        steps+=climb(n-1, dp)+climb(n-2, dp);

        dp[n]=steps;

        // cout<<"Storing value of "<<n<<" in dp"<<endl;
        return steps;
    }


    // int climb(int n, vector<int> &dp)
    // {   
    //     cout<<"Exploring: "<<n<<endl;
    //     if(n<0)
    //         return 0;

    //     if(n==0)
    //         return 1;

    //     if(dp[n]!=-1)
    //     {
    //         cout<<"DP USED"<<endl;
    //         return dp[n];
    //     }

    //     int steps=0;

    //     steps=climbStairs(n-1)+climbStairs(n-2);
        
    //     dp[n]=steps;
    //     cout<<"DP["<<n<<"] SET TO: "<<steps<<endl;
    //     return steps;
    // }
};