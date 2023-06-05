class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;
        int j=-1;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                j=i;
                while(j+1<nums.size() && nums[j]==nums[j+1])
                {
                    j++;
                }
            }
            
            if(j!=-1)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
        result.push_back(j);
        result.push_back(j);
        
        return result;
        
    }
};