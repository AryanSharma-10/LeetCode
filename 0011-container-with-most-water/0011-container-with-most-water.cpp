class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int area=0;
        int temp=0;
        while(i<j)
        {   
            temp=calculateArea(height[i],height[j],j-i);
            if(temp>area)
                area=temp;
            if(height[i]>height[j])
                j--;
            else
                i++;
            cout<<area;
            cout<<"Area is: "<<area<<endl;
        }
        return area;
    }

    int  calculateArea(int a, int b, int length)
    {
        if(a>=b)
            return length*b;
        return length*a;
    }
};