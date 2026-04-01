class Solution {
public:

    void DFS(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& cur)
    {
        cur[r][c] = true;
        vector<vector<int>>dir = {{0,-1},{-1,0},{0,1},{1,0}};

        for(auto e:dir)
        {
            int x = r+e[0], y= c+e[1];
            if(x >= 0 && y >= 0 && x < heights.size() && y < heights[0].size() && !cur[x][y] && heights[x][y] >= heights[r][c] )
                DFS(heights,x,y,cur);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>>atl(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>>pcf(heights.size(),vector<bool>(heights[0].size(), false));
        vector<vector<int>>res;
        for(int i=0;i<heights.size();i++)
        {
            DFS(heights,i,0,pcf);
            DFS(heights,i,heights[0].size()-1,atl);
        }

        for(int j=0;j<heights[0].size();j++)
        {
            DFS(heights,0,j,pcf);
            DFS(heights,heights.size()-1,j,atl);
        }

        for(int i =0;i<heights.size();i++)
            for(int j =0;j<heights[0].size();j++)
            {
                if(pcf[i][j] && atl[i][j])
                    res.push_back({i,j});
            }
        return res;
    }
};
