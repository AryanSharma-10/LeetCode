class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0;
        int zeroes=0;
        int maxOnes=0;
        int b=0;
        int f=0;
        while(f<nums.size())
        {
            if(nums[f]==1)
            {
                count++;
                f++;
            }
            
            else if(nums[f]==0 && zeroes<k)
            {
                count++;
                zeroes++;
                f++;
            }

            else if(nums[f]==0 && zeroes>=k)
            {
                if(nums[b]==1)
                {   
                    b++;
                    count--;
                }

                if(nums[b]==0)
                {   
                    b++;
                    count--;
                    zeroes--;
                }
            }
            
            maxOnes=max(maxOnes,count);
        }

        return maxOnes;
    }
};