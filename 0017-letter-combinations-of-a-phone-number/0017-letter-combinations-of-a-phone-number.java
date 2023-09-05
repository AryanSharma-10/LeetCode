class Solution {
    static char[][] map =  {{'0'},{'0'},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

    public List<String> letterCombinations(String digits) {
        int len = digits.length();
        List<String> result = new ArrayList<>();

        if(len==0)
            return result;

        StringBuilder curr = new StringBuilder();
        allComb(result, digits, curr, len, 0);
        return result;
    }

    static public void allComb(List<String> result, String digits, StringBuilder curr, int n, int m)
    {
        if(n==0)
        {   
            result.add(curr.toString());
            return;
        }
        
        char[] arr = map[digits.charAt(m) - '0'];

        for(int i = 0; i < arr.length; i++)
        {
            StringBuilder temp = new StringBuilder(curr);
            temp.append(arr[i]);
            allComb(result, digits, temp, n-1, m+1);
        }
        
    }
}