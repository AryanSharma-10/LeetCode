class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero=0;
        int f=0;
        int b=0;
        int maxOnes=-1;
        int temp=0;
        int flag=0;

        while(f<nums.size())
        {
            if(nums[f]==1)
            {
                temp++;
                f++;
            }

            else
            {
                if(zero==0)
                {
                    zero++;
                    f++;
                }
                
                else
                {   
                    while(b<nums.size() && nums[b]==1)
                    {
                        b++;
                        temp--;
                    }
                    zero=0;
                    b++;
                    cout<<b<<endl;
                }
            }

            maxOnes=max(temp,maxOnes);
        }

        if(zero==0)
            maxOnes--;

        return maxOnes;
    }
};