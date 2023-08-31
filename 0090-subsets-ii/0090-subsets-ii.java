class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<Integer> subset=new ArrayList<>();
        Set<List<Integer>> result=new HashSet<List<Integer>>();
        result.add(subset);
        Arrays.sort(nums);
        allComb(nums, result, subset, 0);

        List<List<Integer>> resultList = new ArrayList<>();

        Iterator<List<Integer>> value = result.iterator();

        while (value.hasNext()) {
            resultList.add(value.next());
        }

        return resultList;
    }

    public static void allComb(int[] nums, Set<List<Integer>> result, List<Integer> subset, int index)
    {
        if(index==nums.length)
            return;
        
        for(int i=index;i<nums.length;i++)
        {   
            List<Integer> temp = new ArrayList<>(subset);
            temp.add(nums[i]);
            result.add(temp);
            allComb(nums, result, temp, i+1);
        }
    }

}