class Solution {
public:
    int jump(vector<int>& nums) {
        bool route=false;
        vector<int>dp(nums.size(),-1);
        int step=0;
        int min_step=minSteps(nums,0,dp);
        return min_step;
    }

    int minSteps(vector <int> &num, int index,  vector<int>&dp)
    {   
        if(index==num.size()-1)
        {
            return 0;
        }

        int subAns=INT_MAX-num.size();

         if(dp[index]!=-1)
            {
                    return subAns=dp[index];
            }

        int steps=INT_MAX;

        for(int i=1;i<=num[index];i++)
        {   

            if( (index+i<num.size() && ( num[index+i]!=0) || (index+i)==num.size()-1 ) )
            {   
                    subAns=minSteps(num,index+i, dp);
            }

            steps=min(steps, subAns+1);
        }
        
        dp[index]=steps;

        return steps;
    }
           
};
