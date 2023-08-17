class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> solution=new ArrayList<>();
        triangle(solution, 0, numRows);
        return solution;
    }

    public static void triangle(List<List<Integer>> solution, int count, int total)
    {   
        if(count==total)
            return;

        List<Integer> row = new ArrayList<>();
        for(int i=0;i<count+1;i++)
        {
            if(i==0 || i==count)
                row.add(1);
            else
                row.add((solution.get(count-1)).get(i-1)+(solution.get(count-1)).get(i));
        }

        solution.add(row);
        
        triangle(solution, count+1, total);
    }

}