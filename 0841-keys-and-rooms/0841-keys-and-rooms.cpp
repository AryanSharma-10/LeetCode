class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size()+1,-1);
        return exploreRooms(rooms,visited);
    }

    bool exploreRooms(vector<vector<int>>& rooms, vector<int>& visited)
    {   
        vector<int> q;
        for(auto i:rooms[0])
        {
            q.push_back(i);
            cout<<i<<endl;
        }

        visited[0]=1;
        int count=1;

        while(q.size()!=0)
        {   
            if(visited[q[0]]==-1)
            {   
                visited[q[0]]=1;
                for(auto i:rooms[q[0]])
                {
                    if(visited[i]==-1)
                    {   
                        q.push_back(i);
                    }
                } 
                  
                count++;
            }
            
            q.erase(q.begin());
        }
        
        if(count==rooms.size())
            return true;
        
        
        return false;
    }
    
};