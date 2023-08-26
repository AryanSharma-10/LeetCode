class Solution {
    public int rob(int[] nums) {
        int[][] dp=new int[nums.length][2];

        for(int[] i:dp)
        {
            i[0]=i[1]=-1;
        }
        
        int t=max(nums, dp, 0, 0);
        return t;
    }

    public static int max(int[] nums, int[][] dp, int i, int flag)
    {   
        if(i==nums.length-1 && flag==0)
            return nums[i];
        
        else if((i==nums.length-1 && flag==1) || i>=nums.length)
            return 0;

        if(dp[i][flag]!=-1)
            return dp[i][flag];

        int profit=0;
        
        if(i==0)
            profit=nums[i]+max(nums, dp, i+2, 1);
        else
            profit=nums[i]+max(nums, dp, i+2, flag);

        profit=Math.max(profit, max(nums, dp, i+1, flag));

        dp[i][flag]=profit;

        return profit;
    }
}