class Solution {
    public int removeElement(int[] nums, int val) {
        int count = 0;
        int  i = 0;
        int j = 0;
        int len = nums.length;

        while(j < len)
        {
            if(nums[j] != val)
            {
                while(i < len && nums[i] != val)
                {
                    i++;
                }

                if(i < len && j > i)
                {   
                    nums[i] = nums[j];
                    nums[j] = val;
                    j = i;
                }

                count++;
            }

            j++;
        }

        return count;
    }
}