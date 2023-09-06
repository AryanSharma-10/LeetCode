class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int len = nums.length;
        return allComb(nums, target, 0, len);
    }

    public static int allComb(int [] nums, int target, int index, int length)
    {   
        if(target == 0 && index == length)
            return 1;
        

        if(index == length)
            return 0;

        int subAns = 0;

        subAns = allComb(nums, target - nums[index], index+1, length);
        subAns += allComb(nums, target + nums[index], index+1, length);

        return subAns;
    }
}