class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result=strs[0];
        string temp="";
        int c=0;
        for(int i=1;i<strs.size();i++)
        {
            cout<<temp[0];
            while(c<result.size() && c<strs[i].size() && result[c]==strs[i][c])
                c++;
            
            result=result.substr(0, c);
            cout<<result<<endl;
            c=0;
        }

            return result;
        }
};