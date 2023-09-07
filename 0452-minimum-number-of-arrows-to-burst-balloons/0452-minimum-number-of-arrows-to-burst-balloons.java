// class Solution {
//     public int findMinArrowShots(int[][] points) {
//         mergeSort(points);
//         int arrows = 0;
//         int len = points.length;
//         int smallest = Integer.MAX_VALUE;

//         for(int i = 0 ; i < len ; i++)
//         {
//             arrows++;
//             int j = i+1;
//             while(j < len && points[i][1] >= points[j][0] && points[j][0] <= smallest)
//             {
//                 smallest = Math.min(smallest, points[j][1]);
//                 j++;
//             }
//             i = j-1;
//             smallest = Integer.MAX_VALUE;
//         }
        
//         return arrows;
//     }

//     public static void merge(int [][] array, int[][] left, int[][] right)
//     {
//         int lenLeft = left.length;
//         int lenRight = right.length;

//         int i = 0;
//         int j = 0;
//         int k = 0;

//         while(i < lenLeft && j < lenRight)
//         {
//             if(left[i][0] > right[j][0])
//                 array[k++] = right[j++];

//             else if(left[i][0] < right[j][0])
//                 array[k++] = left[i++];
            
//             else
//             {
//                 if(left[i][1] > right[j][1])
//                     array[k++] = right[j++];

//                 else 
//                     array[k++] = left[i++];
//             }
//         }

//         while(i < lenLeft)
//             array[k++] = left[i++];

//         while(j < lenRight)
//             array[k++] = right[j++];

//     }

//     public static void mergeSort(int [][] array)
//     {   
//         if(array.length>1)
//         {
//             int len = array.length;
//             int[][] left = new int[(len)/2][2];
//             int[][] right = new int[(len+1)/2][2];

//             int k=0;

//             for(int i = 0; i < len ; i++)
//             {
//                 if(i<len/2)
//                 {
//                     left[i] = array[i];
//                 }

//                 else
//                 {
//                     right[k++] = array[i];
//                 }
//             }
//             mergeSort(left);
//             mergeSort(right);
//             merge(array, left, right);
//         }
//     }
// }

class Solution {
    public int findMinArrowShots(int[][] points) {
        
        int minNumArrows = 1;
        Arrays.sort(points, new Comparator<int[]>(){
            @Override
            public int compare(int[] i1, int[] i2)
            {
                if(i1[0] < i2[0])
                    return -1;
                else if (i1[0] > i2[0])
                    return 1;
                return 0;
            }
        });
            
        // This is where they will trip you up ( at the merge stage )
        // Wait ... do we actually have to merge here? The intervals have been sorted already
        // No you must merge
        // See if they can be merged
        // If mergeable - overwrite OR write into a new subintervals code ( new ArrayList ) 
        // Ok ... so first we compare (a1,a2) and then next step compare (a2,a3)
        // Now if (a1,a2) had an overlap -> why not make the next a2 = merged(a1,a2)? 
        // That would do a carry over effect then
        int n = points.length;
        int[] candid = new int[2];  // always first interval anyways
        candid[0] = points[0][0];
        candid[1] = points[0][1];
        for(int i = 1; i < n; i++)
        {
            // System.out.printf("Current set = (%d,%d)\n", candid[0], candid[1]);
            int[] next = points[i];
            if(hasOverlap(candid,next))
            {
                int[] merged = mergeInterval(candid,next);
                candid[0] = merged[0];
                candid[1] = merged[1];
            }
            else
            {
                candid[0] = next[0];
                candid[1] = next[1];                
                minNumArrows++;
            }
        }
         
        return minNumArrows;
    }
    
    public boolean hasOverlap(int[] i1, int[] i2)
    {
        boolean hasOverlap = false;
        if(i1[0] <= i2[0] && i2[0] <= i1[1])
            hasOverlap = true;
        if(i2[0] <= i1[0] && i1[0] <= i2[1])
            hasOverlap = true;
        return hasOverlap;
    }
    
    public int[] mergeInterval(int[] i1, int[] i2)
    {
        int[] merged = new int[2];
        merged[0] = Math.max(i1[0],i2[0]);
        merged[1] = Math.min(i1[1],i2[1]);
        return merged;
    }
}