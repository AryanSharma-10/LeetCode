class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size()+1, vector<int> (matrix[0].size()+1,INT_MAX));
        int result=INT_MAX;

        for(int j=0;j<matrix[0].size();j++)
        {
            result=min(result, minCost(matrix,dp,0,j));
        }
        
        return result;
    }

    int minCost(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j)
    {   
        // cout<<"Inside: "<<i<<" "<<j<<endl;
        if(i==matrix.size()-1)
        {
            // cout<<"reached bottom"<<endl;
            return matrix[i][j];
        }
        
        if(dp[i][j]!=INT_MAX)
        {
            // cout<<"Returning: "<<dp[i][j]<<" for dp from "<<i<<" "<<j<<endl;
            return dp[i][j];
        }
        
        int steps=INT_MAX;

        if(j-1>=0 && i+1<matrix.size())
            steps=minCost(matrix, dp, i+1, j-1);

        if(i+1<matrix.size())
            steps=min(steps,minCost(matrix, dp, i+1,j));
        
        if(i+1<matrix.size() && j+1<matrix[0].size())
            steps=min(steps,minCost(matrix, dp, i+1,j+1));
        
        steps+=matrix[i][j];

        dp[i][j]=steps;
        // cout<<"Returning: "<<steps<<" for "<<i<<" "<<j<<endl;
        return steps;
    }
};