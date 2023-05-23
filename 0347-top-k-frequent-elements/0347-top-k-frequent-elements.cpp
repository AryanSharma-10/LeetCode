class Solution {
  
public:
    int findIndex(vector<int> &freq, int target)
    {   
        int index=-1;
        int temp=INT_MAX;
        for(int i=0;i<freq.size();i++)
        {
            if(temp>freq[i])
            {
                temp=freq[i];
                index=i;
            }
        }

        if(freq[index]<target)
        {
            freq[index]=target;
            return index;
        }

        return -1;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> frequency;
        vector<int> result;
        sort(nums.begin(),nums.end());
        int count=1;
        int t=0;
        int index;
        for(int i=0;i<nums.size();i++)
        {   
            if(nums.size()==1)
                result.push_back(nums[i]);
            else{
            while(i+1<nums.size() && nums[i]==nums[i+1])
            {   
                i++;
                count++;
            }

            if(i==nums.size()-1)
            {
                if(nums[i]==nums[i-1])
                    count++;
            }

            if(t<k)
            {   
                result.push_back(nums[i]);
                frequency.push_back(count);
                t++;
            }
            else
            {   
                index=findIndex(frequency, count);
                if(index!=-1)
                {   
                    result[index]=nums[i];
                }
            }

            count=1;
            
            }
        }
        
        return result;
    }
};