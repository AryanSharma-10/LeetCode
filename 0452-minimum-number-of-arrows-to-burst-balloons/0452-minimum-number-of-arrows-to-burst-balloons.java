class Solution {
    public int findMinArrowShots(int[][] points) {
        mergeSort(points);
        int arrows = 0;
        int len = points.length;
        int smallest = Integer.MAX_VALUE;

        for(int i = 0 ; i < len ; i++)
        {
            arrows++;
            int j = i+1;
            while(j < len && points[i][1] >= points[j][0] && points[j][0] <= smallest)
            {
                smallest = Math.min(smallest, points[j][1]);
                j++;
            }
            i = j-1;
            smallest = Integer.MAX_VALUE;
        }
        
        return arrows;
    }

    public static void merge(int [][] array, int[][] left, int[][] right)
    {
        int lenLeft = left.length;
        int lenRight = right.length;

        int i = 0;
        int j = 0;
        int k = 0;

        while(i < lenLeft && j < lenRight)
        {
            if(left[i][0] > right[j][0])
                array[k++] = right[j++];

            else if(left[i][0] < right[j][0])
                array[k++] = left[i++];
            
            else
            {
                if(left[i][1] > right[j][1])
                    array[k++] = right[j++];

                else 
                    array[k++] = left[i++];
            }
        }

        while(i < lenLeft)
            array[k++] = left[i++];

        while(j < lenRight)
            array[k++] = right[j++];

    }

    public static void mergeSort(int [][] array)
    {   
        if(array.length>1)
        {
            int len = array.length;
            int[][] left = new int[(len)/2][2];
            int[][] right = new int[(len+1)/2][2];

            int k=0;

            for(int i = 0; i < len ; i++)
            {
                if(i<len/2)
                {
                    left[i] = array[i];
                }

                else
                {
                    right[k++] = array[i];
                }
            }
            mergeSort(left);
            mergeSort(right);
            merge(array, left, right);
        }
    }
}