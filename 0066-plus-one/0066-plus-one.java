class Solution {
    public int[] plusOne(int[] digits) {
        int i= digits.length-1;
            
        while(i>=0 && digits[i]==9)
        {
            digits[i]=0;
            i--;
        }
                    
        if(i==-1)
        {   
            int arr[]=new int[digits.length+1];
            arr[0]=1;

            for(int j=1;j<arr.length;j++)
                arr[j]=digits[j-1];
                
            return arr;
        }
            
        digits[i]++;
            
        return digits;
    }
}