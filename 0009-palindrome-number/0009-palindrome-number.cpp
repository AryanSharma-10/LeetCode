class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        
        long int num=0;
        int temp=x;
        while(temp>0)
        {
            num=num*10+temp%10;
            temp=temp/10;
        }
        
       if(num==x)
            return true;
        
        return false;
    }
};