class Solution {
    public String minRemoveToMakeValid(String s) {
        int para = 0;
        StringBuilder sb = new StringBuilder(s);
        Stack <Integer> q = new Stack<>();
        int len = s.length();
        int i = 0;
        
        while(i < len)
        {
            Character c = sb.charAt(i);
            if(c == '(')
            {
                // System.out.println(i + ": (");
                para++;
                q.add(i);
                i++;
            }
            else if(c == ')')
            {
                if(para > 0)
                {
                    // System.out.println(i + ": )");
                    para--;
                    i++;
                }
                else
                {
                    // System.out.println(i + " removing : (");
                    sb.delete(i, i + 1);
                    len--;
                }
            }
            else
                i++;
        }
        // System.out.println(para);

        while(para != 0)
        {   
            i = q.pop();
            // System.out.println(i + " removing : (");
            sb.delete(i, i + 1);
            para--;
        }
        return sb.toString();
    }
}