class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        temp.push_back(-1);

        if(nums.size()>0)
            result.push_back(temp);
        
        result[0].clear();
        int flag=0;
        cout<<search(temp,-1)<<endl;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<result.size();j++)
            {
                if( !( search(result[j],nums[i]) ) )
                {
                    result[j].push_back(nums[i]);
                    flag++;
                    break;
                }


            }

            if(flag==0)
            {
                result.push_back(temp);
                result[result.size()-1].clear();
                result[result.size()-1].push_back(nums[i]);
            }
            flag=0;
        }

        return result;
    }

    bool search(vector<int> vect, int target)
    {
        for(int i=0;i<vect.size();i++)
        {
            if(vect[i]==target)
                return true;
        }
        return false;
    }
};