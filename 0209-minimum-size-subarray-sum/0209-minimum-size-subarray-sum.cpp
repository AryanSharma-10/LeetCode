class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int length=0;
        int minLength=INT_MAX;
        int f=0;
        int b=0;
        while(f<nums.size())
        {
            if(sum<target)
            {   
                sum+=nums[f];
                f++;
                length++;
                if(sum>=target)
                    minLength=min(minLength,length);
            }

            else
            {   
                sum-=nums[b];
                b++;
                length--;
                if(sum>=target)
                    minLength=min(minLength,length);
            }

            if(f==nums.size())
            {
                while(sum>=target && b<nums.size())
                {
                    minLength=min(minLength,length);
                    sum-=nums[b];
                    b++;
                    length--;
                }
            }
            
        }

        if(minLength==INT_MAX)
            return 0;
        
        return minLength;
    }
};