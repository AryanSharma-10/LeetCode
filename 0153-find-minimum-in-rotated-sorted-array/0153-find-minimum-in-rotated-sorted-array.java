class Solution {
    public int findMin(int[] nums) {
        int n=0;
        int len=nums.length;

        while(len>n+1 && nums[n]<=nums[n+1])
            n++;
        

        if(n==len-1)
            return nums[0];

        return nums[n+1];
    }
}