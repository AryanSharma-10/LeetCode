class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> subset=new ArrayList<>();
        List<List<Integer>> result=new ArrayList<List<Integer>>();

        result.add(subset);
        allComb(nums, result, subset, 0);
        return result;
    }

    public static void allComb(int[] nums, List<List<Integer>> result, List<Integer> subset, int index)
    {
        if(index==nums.length)
            return;
        
        for(int i=index;i<nums.length;i++)
        {   
            List<Integer> temp = new ArrayList<>(subset);
            temp.add(nums[i]);
            result.add(temp);
            System.out.println("Adding: "+temp);
            System.out.println("result: "+result);
            allComb(nums, result, temp, i+1);
        }
    }

}