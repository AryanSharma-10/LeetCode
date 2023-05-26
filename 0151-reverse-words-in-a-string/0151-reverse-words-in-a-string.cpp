class Solution {
public:
    string reverseWords(string s) {
        string result="";
        string word="";
        int flag=0;
        int start=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {   
                word+=s[i];
                flag=1;
            }
            else if(s[i]==' '  && flag==1)
            {   
                if(start!=0)
                    word=word+" ";
                
                result=word+result;
                word="";
                flag=0;
                start++;
            }
        }
        if(flag==1 && start==0)
            result=word;
        else if(flag==1)
            result=word+" "+result;
        return result;

    }
};