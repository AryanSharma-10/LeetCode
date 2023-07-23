class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()+1,-1);
        return maxPoints(questions,dp,0,questions.size());
    }


    long long maxPoints(vector<vector<int>>& questions,vector<long long>& dp, int index, int size)
    {
        if(index>=size)
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];

        long long ans=max(questions[index][0]+maxPoints(questions,dp,index+questions[index][1]+1,size),maxPoints(questions,dp,index+1,size));
        
        return dp[index]=ans;
    }
};