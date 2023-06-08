class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        cout<<j<<endl;
        while(i<matrix.size() && matrix[i][j]<target)
        {
            cout<<matrix[i][j]<<endl;
            i++;
        }
        if(i>=matrix.size())
            return false;

        return binarySearch(matrix[i],0,matrix[i].size()-1, target);
    }

    bool binarySearch(vector<int> nums, int low, int high, int target)
    {
        while(low<=high)
        {   
            int m = low + (high - low) / 2;

            if(nums[m]==target)
                return true;

            if (nums[m] < target)
                low = m + 1;
 
            else
                high = m - 1;
        }

        return false;
    }

};