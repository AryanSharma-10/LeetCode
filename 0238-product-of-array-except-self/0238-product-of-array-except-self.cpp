class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=1;
        int flag=0;
        for(auto i:nums)
        {
            if(i==0)
            {
                flag++;
                if(flag==2)
                {
                    vector<int> result(nums.size(),0);
                    return result;
                }
            }

            else
                n*=i;
        }

        vector<int> result;

        if(flag==0)
        {
            for(auto i:nums)
                result.push_back(n/i);
        }

        else if(flag==1)
        {
            for(auto i:nums)
            {
                if(i==0)
                    result.push_back(n);
                else
                    result.push_back(0);
            }
        }

        return result;
    }
};