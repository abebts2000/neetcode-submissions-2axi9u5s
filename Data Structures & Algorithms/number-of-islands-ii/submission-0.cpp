class Solution {
public:
    unordered_map<int,int>p,r;
    int find(int x)
    {
        if(x!=p[x])
            p[x] = find(p[x]);
        return p[x];
    }

    bool union2(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if(px != py)
        {
            if(r[px] < r[py])
            {
                r[py] += r[px];
                p[px] = py;
            }
            else
            {
                r[px] += r[py];
                p[py] = px;
            }
            return true;
        }
        return false;
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        queue<int>q;
        vector<vector<int>>T(m,vector<int>(n,0));
        vector<vector<int>>dir = {{-1,0},{0,-1},{1,0},{0,1}};
        int c = 0;
        vector<int>res;
        for(auto e:positions)
        {
            if (T[e[0]][e[1]] == 1) {
                res.push_back(c);
                continue;
            }
            T[e[0]][e[1]] = 1;
            int cell = e[0]*n+e[1];
            p[cell] = cell;
            r[cell] = 1;
            c++;
            for(auto g:dir)
            {
                int x = e[0]+g[0],y= e[1]+g[1];
                int cell2 = x*n+y;
                if(x>=0 && x<m && y>=0 && y<n && T[x][y] ==1)
                {
                    if(union2(cell,cell2))
                        c--;
                }
            }
            res.push_back(c);
        }
        return res;
        
    }
};
