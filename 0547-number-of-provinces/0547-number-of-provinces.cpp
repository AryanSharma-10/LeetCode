class Solution {
public:
    int findCircleNum(vector<vector<int>>& is){
        return dfs(is);
    }

    int dfs(vector<vector<int>>& graph)
    {
        vector<int> visited(graph.size()+1,-1);
        vector<int> q;

        int count=0;

        for(int i=0;i<graph.size();i++)
        {   
            if(visited[i]==-1)
            {   
                visited[i]=1;
                for(int j=0;j<graph[i].size();j++)
                {
                    if(graph[i][j]==1 && visited[j]==-1 && i!=j)
                    {   
                        q.push_back(j);
                    }
                }

                while(q.size()!=0)
                {   
                    visited[q[0]]=1;
                    for(int j=0;j<graph[q[0]].size();j++)
                    {   
                        if(graph[q[0]][j]==1 && visited[j]==-1 && q[0]!=j)
                        {   
                            q.push_back(j);
                        }
                    }
                    q.erase(q.begin());
                }

                count++;
            }
            
        }

        return count;
    }
};