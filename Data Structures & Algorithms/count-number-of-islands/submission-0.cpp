class Solution {
public:
    void DFS(vector<vector<char>>& grid, unordered_set<int>&visited, int r, int c)
    {
        if(r>=grid.size() || r < 0 || c>=grid[0].size() || c < 0 || grid[r][c] == '0')
         return;
        int cell = r*grid[0].size()+c;
        if(visited.find(cell) != visited.end())
          return;
        visited.insert(cell);
        vector<vector<int>>dir = {{-1,0},{0,-1},{1,0},{0,1}};
        for(auto e:dir)
        {
            int rn = r+e[0];
            int cn = c+e[1];
            DFS(grid,visited,rn,cn);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        unordered_set<int>visited;
        for(int i =0;i<grid.size();i++)
            for(int j = 0;j<grid[0].size();j++)
            {
                int cell = i*grid[0].size()+j;
                if(grid[i][j] =='1' && visited.find(cell) == visited.end())
                {
                    count++;
                    DFS(grid,visited, i, j);
                }
            }
        return count;
    }
};
