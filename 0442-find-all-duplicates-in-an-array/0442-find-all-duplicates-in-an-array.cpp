class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int max=*max_element(nums.begin(), nums.end());
        
        vector<int> temp(max+1);
        vector<int> result;
        
        for(int i=0; i < nums.size() ; i++)
        {   
            if(temp[nums[i]]==1)
                result.push_back(nums[i]);
            else
                temp[nums[i]]=1;

        }
        
        return result;
    }
};