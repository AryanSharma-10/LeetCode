class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        for(j;j<nums.size();j++)
        {   
            nums[i++]=nums[j];

            while(j+1<nums.size() && nums[j]==nums[j+1])
                j++;
            
        }

        return i;
    }
};