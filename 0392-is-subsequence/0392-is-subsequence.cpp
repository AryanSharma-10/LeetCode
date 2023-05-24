class Solution {
public:
    bool isSubsequence(string child, string parent) {
        if(child==parent)
            return true;
            
        int j=0;
        for(int i=0;i<parent.size();i++)
        {
            if(child[j]==parent[i])
                j++;
            
            if(j>=child.size())
                return true;
        }

        return false;
    }
};