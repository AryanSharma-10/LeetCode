class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int flag=0;

        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                count++;
                flag=1;
            }
            else if(flag==1 && s[i]==' ')
                break;
        }

        return count;
    }
};