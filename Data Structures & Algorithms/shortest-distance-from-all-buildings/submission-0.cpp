class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        unordered_map<int,int>empty;
        unordered_map<int,int>totaldist;
        vector<vector<int>>bldgs;
        vector<int>candidates;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for(int r =0;r<grid.size();r++)
        {
            for(int c =0;c<grid[0].size();c++)
            {
                if(grid[r][c] == 1)
                    bldgs.push_back({r,c});
            }
        }

        for(auto e:bldgs)
        {
            queue<tuple<int,int,int>>q;
            q.push({e[0],e[1],0});
            unordered_set<int>visited;
            visited.insert(e[0]*COLS + e[1]);
            vector<vector<int>>dirs = {{-1,0},{0,-1},{1,0},{0,1}};

            while(!q.empty())
            {
                auto [x,y,dist] = q.front();
                q.pop();
                int cell = x*COLS+y;
                if(grid[x][y] == 0)
                {
                    empty[cell] += 1;
                    totaldist[cell] += dist;
                }

                for(auto e:dirs)
                {
                    int nx = x+e[0];
                    int ny = y+e[1];
                    int celln = nx*COLS + ny;
                    if(nx >=0 && ny >=0 && nx < ROWS && ny < COLS && 
                        visited.find(celln) == visited.end() && grid[nx][ny] == 0)
                        {
                           visited.insert(celln);
                           q.push({nx,ny,dist+1}); 
                        }
                }
            }
        } 
        int smallest = INT_MAX;
        for(auto e:empty)
        {
            if(e.second == bldgs.size())
            {
                smallest = min(smallest,totaldist[e.first]);
            }
        }

        if(smallest == INT_MAX)
            return -1;
        return smallest;
    }
};
