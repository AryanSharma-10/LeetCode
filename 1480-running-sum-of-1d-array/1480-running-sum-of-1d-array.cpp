class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        int sum;
        vector <int> result;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            result.push_back(sum);
            cout<<sum<<"  ";
        }

        return result;
    }
};