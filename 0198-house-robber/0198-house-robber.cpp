class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp (nums.size()+1,-1);

        return max(maxMoney(nums,dp,0,nums.size()), maxMoney(nums,dp,1,nums.size()));
    }

    int maxMoney(vector<int>& num, vector<int>&dp, int i, int size)
    {
        if(i>=size)
            return 0;

        if(i==size-1)
            return num[i];
        
        if(dp[i]!=-1)
            return dp[i];

        int ans=num[i];

        ans+=max(maxMoney(num,dp,i+2,size),maxMoney(num,dp,i+3,size));
        
        dp[i]=ans;

        return ans;
    }
};