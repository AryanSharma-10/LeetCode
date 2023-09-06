class Solution {
    static int maxCookies;
    public int distributeCookies(int[] cookies, int k) {
        maxCookies = Integer.MAX_VALUE;
        int len = cookies.length;
        int[] kids = new int[k];
        cookiesDistribution(cookies, 0, kids, k, len);
        return maxCookies;
    }

    public static void cookiesDistribution(int[] cookies, int index, int[] kids, int k, int len)
    {
        if(index == len)
        {   
            int temp = 0;
            for(int i : kids)
                temp = Math.max(temp, i);
            
            maxCookies = Math.min(maxCookies, temp);
            return;
        }


        for(int i = 0 ; i < k ; i++)
        {   
            kids[i] += cookies[index];
            cookiesDistribution(cookies, index+1, kids, k, len);
            kids[i] -= cookies[index];
        }

    }
}