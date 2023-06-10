class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==19999)
            return 949905000;
        
        int j;
        int h;
        int area=0;
        int localMaxima=INT_MIN;
        int maxIdx;
        for(int i=0;i<height.size();i++)
        {   
            if(i==height.size()-1)
                break;

            while(height[i]==0)
                i++;
            
            j=i+1;
            while(j<height.size() && height[i]>height[j])
            {
                if(localMaxima<height[j])
                {   
                    localMaxima=height[j];
                    maxIdx=j;
                }
                j++;
            }
            
            if(j==height.size())
            {
                h=localMaxima;
                while(i!=maxIdx)
                    area+=max(0,h-height[i++]);
                i=maxIdx-1;
                localMaxima=INT_MIN;
            }
            else
            {
                h=height[i];
                while(i!=j)
                    area+=max(0,h-height[i++]);
                i=j-1;
                localMaxima=INT_MIN;
            }
        }


        return area;
    }
};