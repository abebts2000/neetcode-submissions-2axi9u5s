class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int INF=2147483647;
        for(int i =0;i<grid.size();i++)
            for(int j =0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 0)
                    q.push({i,j});
            }

        while(!q.empty())
        {
            auto [r,c] = q.front();
    
            q.pop();
            vector<vector<int>>dir = {{-1,0},{0,-1},{1,0},{0,1}};
            for(auto e:dir)
            {
                int x = r+e[0], y= c+e[1];

                if(x >= 0 && y >=0 && x < grid.size() && y < grid[0].size() && grid[x][y] == INF)
                {
                    grid[x][y] = grid[r][c]+1;
                    q.push({x,y});
                }
            }
        }
    }
};
