class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x); y = abs(y);
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},0});
        vector<vector<int>>dir = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
        unordered_set<long long>visited;
        visited.insert(0);
        while(!q.empty())
        {
            auto [cell, dist] = q.front();
            q.pop();
            int tx = cell.first,ty=cell.second;
            if(tx==x && ty == y)
                return dist;
            for (auto e:dir)
            {
                int nx = tx+e[0],ny=ty+e[1];
                long long hashcell = (long long)(nx + 302) * 1000 + (ny + 302);
                if(nx >= -2 && ny >= -2 && visited.find(hashcell) == visited.end())
                {
                    visited.insert(hashcell);
                    q.push({{nx,ny},dist+1});
                }

            }
        }
        return -1;


    }
};
