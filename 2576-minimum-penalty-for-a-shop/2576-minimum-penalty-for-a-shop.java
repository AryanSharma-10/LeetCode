class Solution {
    public int bestClosingTime(String str) {
        int len=str.length();
        int y=0;
        int n=0;
        int penalty=Integer.MAX_VALUE;
        int index=0;

        for(int i=0;i<len;i++)
        {
            if(str.charAt(i)=='Y')
                y++;
        }

        if(y==len)
            return len;

        for(int i=0;i<len;i++)
        {
            int temp=y;

            if(str.charAt(i)=='Y')
                y--;
            
            if(penalty>temp+n)
            {
                penalty=temp+n;
                index=i;
            }

            if(str.charAt(i)=='N')
                n++;
        }

        if(n<penalty)
        {
            return len;
        }
        
        return index;
    }
}