class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool route=false;
        vector<int>dp(nums.size(),0);

        return path(nums,0,route,dp);
    }

    bool path(vector<int>& nums, int index, bool route, vector<int>&dp)
    {   
        if(index==nums.size()-1)
            return true;
        
        
        for(int i=1;i<=nums[index];i++)
        {   
            if(index+i<nums.size() && dp[index+i]!=1)
                route=path(nums, i+index, route,dp);
            
            if(route)
                return true;
        }

        dp[index]=1;
        
        return route;
    }

           
};