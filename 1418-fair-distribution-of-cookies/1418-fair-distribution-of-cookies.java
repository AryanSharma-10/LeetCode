// class Solution {
//     static int maxCookies;
//     public int distributeCookies(int[] cookies, int k) {
//         maxCookies = Integer.MAX_VALUE;
//         int len = cookies.length;
//         int[] kids = new int[k];
//         cookiesDistribution(cookies, 0, kids, k, len);
//         return maxCookies;
//     }

//     public static void cookiesDistribution(int[] cookies, int index, int[] kids, int k, int len)
//     {
//         if(index == len)
//         {   
//             int temp = 0;
//             for(int i : kids)
//                 temp = Math.max(temp, i);
            
//             maxCookies = Math.min(maxCookies, temp);
//             return;
//         }


//         for(int i = 0 ; i < k ; i++)
//         {   
//             kids[i] += cookies[index];
//             cookiesDistribution(cookies, index+1, kids, k, len);
//             kids[i] -= cookies[index];
//         }

//     }
// }

class Solution {
    private int dfs(int idx, int[] distribute, int[] cookies, int k, int zeroCount) {
        if (cookies.length - idx < zeroCount) {
            return Integer.MAX_VALUE;   
        }

        if (idx == cookies.length) {
            int unfairness = Integer.MIN_VALUE;
            for (int value : distribute) {
                unfairness = Math.max(unfairness, value);
            }
            return unfairness;
        }
        
        int minUnfairness = Integer.MAX_VALUE;
        for (int j = 0; j < k; ++j) {
            zeroCount -= distribute[j] == 0 ? 1 : 0;
            distribute[j] += cookies[idx];
            
            minUnfairness = Math.min(minUnfairness, dfs(idx + 1, distribute, cookies, k, zeroCount));
            
            distribute[j] -= cookies[idx];
            zeroCount += distribute[j] == 0 ? 1 : 0;
        }
        
        return minUnfairness;
    }
    
    public int distributeCookies(int[] cookies, int k) {
        int[] distribute = new int[k];
        
        return dfs(0, distribute, cookies, k, k);
    }
}