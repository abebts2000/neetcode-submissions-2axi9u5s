class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //BFS from the chest locations
        //water can't be traversed
        queue<tuple<int,int,int>>q;
        for(int i =0;i<grid.size();i++)
        for(int j =0;j<grid[0].size();j++)
        {
            if(grid[i][j]==0)
                q.push({i,j,0});
        }
        vector<vector<int>>dirs = {{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty())
        {
            auto [x,y,dist] = q.front();
            q.pop();
            for(auto dir:dirs)
            {
                int dx = x+dir[0], dy = y+dir[1];
                if(dx < 0 || dy < 0 || dx >= grid.size() || dy >= grid[0].size() || grid[dx][dy] == -1 || grid[dx][dy] == 0 || grid[dx][dy] != 2147483647)
                    continue;
                q.push({dx,dy,dist+1});
                grid[dx][dy] = min(grid[dx][dy],dist+1);
            }
            
        }
        
    }
};
