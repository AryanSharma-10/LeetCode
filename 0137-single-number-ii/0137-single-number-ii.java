class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;

        for(int i=0;i<n;i=i+3)
        {
            if( i+1>=n || nums[i]!=nums[i+1])
                return nums[i];
        }

        return n;
    }
}