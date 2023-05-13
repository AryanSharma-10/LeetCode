class Solution {
public:
    vector<pair<int, int>> visited;

    bool search(int x, int y)
    {   
        for(auto i: visited)
            if(i.first==x && i.second==y)
            {   
                return false;
            }

        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target=image[sr][sc];
        if(target==color)
            sameFill(image, sr, sc, color, target);
        else
            diffFill(image, sr, sc, color, target);
        return image;
    }

    vector<vector<int>> diffFill(vector<vector<int>>& image, int sr, int sc, int color, int target)
    {
        if(image[sr][sc]==target)
        {   
            visited.push_back(make_pair(sr,sc));
            image[sr][sc]=color;
            if(image.size()>sr-1 && image[0].size()>sc)
                diffFill(image, sr-1, sc, color, target);
            if(image.size()>sr && image[0].size()>sc+1)
                diffFill(image, sr, sc+1, color, target);
            if(image.size()>sr+1 && image[0].size()>sc)
                diffFill(image, sr+1, sc, color, target);
            if(image.size()>sr && image[0].size()>sc-1)
                diffFill(image, sr, sc-1, color, target);
        }

        return image;
    }

    vector<vector<int>> sameFill(vector<vector<int>>& image, int sr, int sc, int color, int target)
    {
        if(image[sr][sc]==target && search(sr,sc))
        {   
            visited.push_back(make_pair(sr,sc));
            image[sr][sc]=color;
            if(image.size()>sr-1 && image[0].size()>sc)
                sameFill(image, sr-1, sc, color, target);
            if(image.size()>sr && image[0].size()>sc+1)
                sameFill(image, sr, sc+1, color, target);
            if(image.size()>sr+1 && image[0].size()>sc)
                sameFill(image, sr+1, sc, color, target);
            if(image.size()>sr && image[0].size()>sc-1)
                sameFill(image, sr, sc-1, color, target);
        }
        
        return image;
    }
};