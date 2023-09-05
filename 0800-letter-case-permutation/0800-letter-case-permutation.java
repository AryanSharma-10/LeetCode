class Solution {
    static List<String> result;
    public List<String> letterCasePermutation(String s) {
        StringBuilder str = new StringBuilder(s);
        result = new ArrayList<>();
        int len = str.length();

        allComb(str, 0, len);

        return result;
    }

    public static void allComb(StringBuilder str, int index, int len)
    {   
        if(len == index)
        {
            result.add(str.toString());
            return;
        }

        if( ( 65<=str.charAt(index) && str.charAt(index)<=90 ) || ( 97<=str.charAt(index) && str.charAt(index)<=122 ) )
        {
            StringBuilder temp = str;

            str.setCharAt(index, Character.toUpperCase(str.charAt(index)) );
            allComb(temp, index+1, len);

            str.setCharAt(index, Character.toLowerCase(str.charAt(index)) );
            allComb(temp, index+1, len);
        }
        else
        {
            allComb(str, index+1, len);
        }
    }


}