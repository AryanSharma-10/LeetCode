class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length();
        int i=0;
        cout<<n;
        while(i+n<=haystack.length())
        {             
            if(haystack.substr(0+i,n)==needle)
                return i;
            i++;
        }
        
        return -1;
    }
};