class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        int len = groupSizes.length;

        List<List<Integer>> result = new ArrayList<>();
        int [] visited = new int[len];
        
        int i = 0;

        while(i < len)
        {   
            if(visited[i]==0)
            {
                List<Integer> temp = new ArrayList <>();
                temp.add(i);

                int count = 1;
                int j = i+1;

                while(count < groupSizes[i] && j < len)
                {   
                    if(groupSizes[i] == groupSizes[j] && visited[j]==0)
                    {
                        visited[j]=1;
                        temp.add(j);
                        count++;
                    }

                    j++;
                }

                result.add(temp);
            }

            i++;
        }

        return result; 
    }
}