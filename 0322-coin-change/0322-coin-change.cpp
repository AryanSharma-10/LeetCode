class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0]=0;
        int n=minchange(coins, amount, dp);
        if(n==INT_MAX)
            return -1;
        return n;
    }

    int minchange(vector<int> coins, int amount, vector<int>& dp)
    {   
        if(amount==0)
        {   
            return 0;
        }
    
        int ans = INT_MAX;

        for(int i=0;i<coins.size();i++)
        {   
            if(amount-coins[i]>=0){
                int subAns;
                if(dp[amount-coins[i]]!=-1)
                    subAns=dp[amount-coins[i]];
                else
                    subAns = minchange(coins, amount-coins[i], dp);

                if(subAns!=INT_MAX && subAns+1<ans)
                {   
                    ans=subAns+1;
                }
            }
        }

        dp[amount]=ans;
        

        return ans;
    }
};