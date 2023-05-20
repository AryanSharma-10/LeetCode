class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> time;
        for(int i=0;i<dist.size();i++)
            time.push_back((float)dist[i]/speed[i]);
        
        cout<<endl;
        int count=0;
        sort(time.begin(), time.end());
        for(int i=0;i<time.size();i++)
        {
            if(i<time[i])
            {   
                count++;
            }
            else
                break;
        }
        return count;
    }
};