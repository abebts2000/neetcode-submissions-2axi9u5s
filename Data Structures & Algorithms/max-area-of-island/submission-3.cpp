class Solution {
public:

    void DFS(vector<vector<int>>& grid, int r, int c, unordered_set<int>&st,int& count)
    {
        int cell = grid[0].size()*r+c;
        if(r < 0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c] ==0 || st.find(cell) != st.end())
            return;
        st.insert(cell);
        count+=1;
        vector<vector<int>>dir = {{0,-1},{-1,0},{0,1},{1,0}};
        for(auto e:dir)
        {
            int x = r+e[0];
            int y = c+e[1];
            DFS(grid,x,y,st,count);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        unordered_set<int>st;
        int mx =0;
        for(int i =0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int cell = grid[0].size()*i+j;
                if(grid[i][j] == 1 && st.find(cell) == st.end())
                {
                    int c =0;
                    DFS(grid,i,j,st,c);
                    mx = max(c,mx);
                }
            }
        }
        return mx;
    }
};
