class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> vi(matrix.size(),0);
        vector<int> vj(matrix[0].size(),0);
        vector<vector<int>> temp = matrix;

        for(int i=0;i<temp.size();i++)
        {
            for(int j=0;j<temp[0].size();j++)
            {
                if(temp[i][j]==0)
                    change(matrix, i, j, vj, vi);
            }
        }
    }

    void change(vector<vector<int>>& matrix, int i, int j, vector<int> vj, vector<int>& vi)
    {   
        int c=1;
        

        // if(vj[i]!=1)
        // {
        // //Left
        while(j-c>=0)
        {   
            // cout<<"Changing ("<<i<<","<<j-c<<")"<<endl;
            matrix[i][j-c]=0;
            c++;
        }   
        c=1;

        //Right
        while(j+c<matrix[0].size())
        {   
            // cout<<"Changing ("<<i<<","<<j+c<<")"<<endl;
            matrix[i][j+c]=0;
            c++;
        }   
        c=1;
        // }

        // if(vi[j]!=1){ 
        //Top
        while(i-c>=0)
        {   
            // cout<<"Changing ("<<i-c<<","<<j<<")"<<endl;
            matrix[i-c][j]=0;
            c++;
        }   
        c=1;

        //Bottom
        while(i+c<matrix.size())
        {   
            // cout<<"Changing ("<<i+c<<","<<j<<")"<<endl;
            matrix[i+c][j]=0;
            c++;
        }   
        c=1;

        // }
        
        // vj[i]=i;
        // vi[j]=1;
    }
};