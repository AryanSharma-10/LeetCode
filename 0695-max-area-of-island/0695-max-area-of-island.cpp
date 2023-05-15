class Solution {
    int size=0;
    int temp=0;

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<char> t(n,'n');
        vector<vector<char>> visited(m,t);


        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if( grid[i][j]==1 && visited[i][j]=='n' )
                {
                    findSize(grid, i, j, visited);
                }

                if(temp>size)
                {
                    size=temp;
                }
                
                cout<<endl<<endl;
                temp=0;
            }
        }

        return size;
    }
    
    void findSize(vector<vector<int>>& grid, int i, int j, vector<vector<char>>& visited)
    {   
        temp++;
        visited[i][j]='y';
        
        if(i-1>=0 && grid[i-1][j]==1 && visited[i-1][j]=='n')
            {   
                findSize(grid, i-1, j, visited);
            }
            
        if(j+1<grid[0].size() && grid[i][j+1]==1 && visited[i][j+1]=='n' )
            {   
                findSize(grid, i, j+1, visited);
            }

        if(i+1<grid.size() && grid[i+1][j]==1 && visited[i+1][j]=='n')
            {   
                findSize(grid, i+1, j, visited);
            }
        
        if(j-1>=0 && grid[i][j-1]==1 && visited[i][j-1]=='n')
            {   
                findSize(grid, i, j-1, visited);
            }
        
    }
    
};