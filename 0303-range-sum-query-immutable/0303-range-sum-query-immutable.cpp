class NumArray {
public:
    vector<int> sumMat; 
    NumArray(vector<int>& nums) {
        int n = nums.size(), prefix=nums[0];
        sumMat = vector<int>(n+1);
        sumMat[0]=0; sumMat[1]=nums[0];
        
        for (int i=1; i<n; i++){
            prefix+=nums[i];
            sumMat[i+1]=prefix;
        }
    }
    
    int sumRange(int left, int right) {
        return (sumMat[right+1]-sumMat[left]);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */