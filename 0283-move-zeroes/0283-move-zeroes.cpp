class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1)
            return;

        for(int i=0;i<nums.size();i++)
        {   
            if(nums[i]==0)
            {
                int j=i+1;
                while(j<nums.size() && nums[j]==0)
                {
                    j++;
                }

                if(j<nums.size())
                    swap(nums[j],nums[i]);
            }
        }
    }
};