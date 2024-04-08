class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        Queue <Integer> q = new LinkedList<>();

        int len = students.length;
        int i = 0;
        int j = 0;
        int circle = 0;
        int square = 0;
        while(i < len)
        {
            if(students[i] == sandwiches[j])
            {
                i++;
                j++;
            }
            else
            {   
                if(students[i] == 0)
                    circle++;
                else
                    square++;

                q.add(students[i]);
                i++;
            }
        }

        while(j < len)
        {
            if(sandwiches[j] == 0 && circle == 0)
            {
                return square;
            }
            else if(sandwiches[j] == 1 && square == 0)
            {
                return circle;
            }
            else
            {
                if(sandwiches[j] == 0)
                    circle--;
                else
                    square--;
                
                j++;
            }
        }

        return 0;
    }
}