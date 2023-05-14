class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int alive=0;

        vector<vector<int>> copy(board.begin(), board.end());
        
        int m=copy.size();
        int n=copy[0].size();

        cout<<m;
        cout<<n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-1<m && i-1>=0)
                {
                    if(copy[i-1][j]==1)
                        alive++;
                }
                if(i-1<m && j+1<n && i-1>=0)
                {
                    if(copy[i-1][j+1]==1)
                        alive++;
                }
                if(j+1<n)
                {
                    if(copy[i][j+1]==1)
                        alive++;
                }
                if(i+1<m && j+1<n)
                {
                    if(copy[i+1][j+1]==1)
                        alive++;
                }
                if(i+1<m)
                {
                    if(copy[i+1][j]==1)
                        alive++;
                }
                if(i+1<m && j-1<n && j-1>=0)
                {
                    if(copy[i+1][j-1]==1)
                        alive++;
                }
                if(j-1<n && j-1>=0)
                {
                    if(copy[i][j-1]==1)
                        alive++;
                }
                if(i-1<m && j-1<n && j-1>=0 && i-1>=0)
                {
                    if(copy[i-1][j-1]==1)
                        alive++;
                }

                cout<<endl<<endl;
                if(alive<2)
                    board[i][j]=0;
                
                if(alive>3)
                    board[i][j]=0;
                
                if(copy[i][j]==0 && alive==3)
                    board[i][j]=1;
                
                
                alive=0;
            }
        }
    }
};