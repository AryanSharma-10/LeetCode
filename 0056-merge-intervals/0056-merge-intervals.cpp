class Solution {
public:
void merge(vector<vector<int>> &v, int s, int m, int e)
{
    vector<vector<int>> temp;

    int i, j;
    i = s;
    j = m + 1;

    while (i <= m && j <= e)
    {

        if (v[i][0] < v[j][0])
        {
            temp.push_back(v[i]);
            ++i;
        }
        else if (v[i][0] > v[j][0])
        {
            temp.push_back(v[j]);
            ++j;
        }
        else
        {
            if (v[i][1] <= v[j][1])
            {
                temp.push_back(v[i]);
                ++i;
            }
            else 
            {
                temp.push_back(v[j]);
                ++j;
            }
        }
    }

    while (i <= m)
    {
        temp.push_back(v[i]);
        ++i;
    }

    while (j <= e)
    {
        temp.push_back(v[j]);
        ++j;
    }

    for (int i = s; i <= e; ++i)
        v[i] = temp[i - s];
}


void MergeSort(vector<vector<int>> &v, int s, int e)
{
    if (s < e)
    {
        int m = (s + e) / 2;
        MergeSort(v, s, m);
        MergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n=intervals.size();
        int start;
        int end;
        MergeSort(intervals,0,intervals.size()-1);

        cout<<endl;
        for(int i=0;i<n;i++)
        {
            start=intervals[i][0];
            end=intervals[i][1];

            while(i+1<n && end>=intervals[i+1][0])
            {   
                i++;
                end=max(end,intervals[i][1]);
            }

            result.push_back(vector<int> {start,end});   
        }
        return result;
    }
};