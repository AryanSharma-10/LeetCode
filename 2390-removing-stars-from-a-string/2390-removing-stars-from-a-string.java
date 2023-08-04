class Solution {
    public String removeStars(String s) {
        int j=0;
        String result="";
        int count=0;
        int i=s.length()-1;

        while(i>=0)
        {
            if(s.charAt(i)=='*')
            {
                count++;
            }

            else
            {
                if(count==0)
                {
                    result=s.charAt(i)+result;
                }

                else
                {
                    count--;
                }
            }
        
            i--;
        }

        return result;
    }
}