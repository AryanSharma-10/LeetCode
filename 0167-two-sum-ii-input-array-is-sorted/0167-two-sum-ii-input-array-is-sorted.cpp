class Solution {
public:

int binarySearch(vector<int> arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (arr[m] == x)
            return m;
 
        if (arr[m] < x)
            l = m + 1;
 
        else
            r = m - 1;
    }
    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    int index;
    int dpIndex;
    vector<int> result;
    vector<int> dp;
    for(int i=0;i<numbers.size();i++)
    {   
        dpIndex=binarySearch(dp, 0, dp.size()-1,numbers[i]);
        if(dpIndex==-1)
        {
            index=binarySearch(numbers, i+1, numbers.size()-1,target-numbers[i]);
            if(index!=-1)
            {
                result.push_back(i+1);
                result.push_back(index+1);
                break;
            }
            dp.push_back(numbers[i]);
        }
    }
    return result;
    }
};