class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        vector<int> result;
        while(i<m && j<n)
        {
            if(nums1[i]>nums2[j])
            {
                cout<<"Pushing "<<nums2[j]<<" from num2"<<endl;
                result.push_back(nums2[j]);
                j++;
            }
                
            else
            {
                result.push_back(nums1[i]);
                cout<<"Pushing "<<nums1[i]<<" from num1"<<endl;
                i++;
            }
        }
        
        while(j<n)
        {
            cout<<"Pushing "<<nums2[j]<<" from num2"<<endl;
            result.push_back(nums2[j]);
            j++;
        }
        
        while(i<m)
        {
            result.push_back(nums1[i]);
            cout<<"Pushing "<<nums1[i]<<" from num1"<<endl;
            i++;
        }
        
        for(int i=0;i<m+n;i++)
        {
            nums1[i]=result[i];
            cout<<i<<" ";
        }
    }
};