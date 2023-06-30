class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(minCost(cost,dp,0),minCost(cost,dp,1));
    }

    int minCost(vector<int>& cost, vector<int>& dp, int i)
    {
        if(i>=cost.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];

        int path=min(minCost(cost, dp, i+1),minCost(cost, dp, i+2));

        path+=cost[i];

        return dp[i]=path;
    }
};