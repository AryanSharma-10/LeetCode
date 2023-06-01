class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count=1;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]<=0 && i+1<nums.size())
                i++;

            if(nums[i]!=count)
                return count;

            while(i+1<nums.size() && nums[i+1]==count)
                i++;

            count++;
        }
        
        return count;
    }
    
    
};