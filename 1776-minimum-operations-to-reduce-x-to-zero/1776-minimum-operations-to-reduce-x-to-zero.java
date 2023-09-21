class Solution {
    public int minOperations(int[] nums, int target) {
        int front = 0;
        int back = 0;
        int sum = 0;
        int totalSum = 0;
        int maxSize = 0;
        int currSize = 0;
        int len = 0;

        for(int i : nums)
        {
            len++;
            totalSum+=i;
        }
        
        if(len == 1)
        {
            if(nums[0] == target)
                return 1;
        }

        if(totalSum - target < 0)
            return -1;
        
        if(totalSum - target == 0)
            return len;
        

        while(front < len)
        {   
            if(sum < totalSum - target)
            {
                sum+=nums[front++];
                currSize++;
            }

            else if(sum > totalSum - target)
            {   
                sum-=nums[back++];
                currSize--;
            }

            else
            {   
                maxSize = Math.max(currSize, maxSize);
                if(back<front)
                {
                    sum-=nums[back++];
                    currSize--;
                }
            }

            if(front >= len)
            {   
                while(back < front && sum > totalSum - target)
                {
                    sum-=nums[back++];
                    currSize--;
                }

                if(sum == totalSum - target)
                {
                    maxSize = Math.max(currSize, maxSize);
                }


                break;
            }

        }

        if(maxSize == 0)
            return -1;
        
        return len-maxSize;
    }
}