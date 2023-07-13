class Solution {
public:
    void combinations(vector<vector<int>> &result, vector<int> &nums, vector<int> comb, int n, int k)
{
    if (k == 0)
    {
        result.push_back(comb);
        return;
    }

    for (int i = n; i < nums.size(); i++)
    {
        comb.push_back(i + 1);
        combinations(result, nums, comb, n + 1, k - 1);
        comb.erase(comb.end() - 1);
        n++;
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<int> nums;

    for (int i = 0; i < n; i++)
        nums.push_back(i + 1);

    vector<vector<int>> result;
    vector<int> comb;

    combinations(result, nums, comb, 0, k);
    return result;
}

    
};