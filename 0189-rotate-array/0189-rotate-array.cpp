class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result(nums.size());
        int index;
        for(int i=0;i<nums.size();i++)
        {
            index=(i+k)%nums.size();
            result[index]=nums[i];
        }
        
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=result[i];
        }
        
    }
};