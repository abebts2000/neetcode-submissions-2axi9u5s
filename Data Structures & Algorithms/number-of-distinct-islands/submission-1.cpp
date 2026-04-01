class Solution {
public:

    void DFS(vector<vector<int>>& grid, int r, int c, string &sofar, char move, unordered_set<int>&visited)
    {
        if(r<0 || c < 0 || r>=grid.size() || c >= grid[0].size() || grid[r][c] == 0 || visited.find(r*grid[0].size()+c) != visited.end() )
        {
            return;
        }
        visited.insert(r*grid[0].size()+c);
        sofar += move;
        DFS(grid,r,c-1,sofar,'L',visited);
        DFS(grid,r-1,c,sofar,'U',visited);
        DFS(grid,r,c+1,sofar,'R',visited);
        DFS(grid,r+1,c,sofar,'D',visited);

        sofar+="B";
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<int>visited;
        unordered_set<string>paths;
        for(int i =0;i<grid.size();i++)
            for(int j =0;j<grid[0].size();j++)
            {
                int cell = i*grid[0].size()+j;
                if(grid[i][j] == 0 || visited.find(cell) != visited.end())
                    continue;
                string sofar="";
                DFS(grid,i,j,sofar,'S',visited);
                //cout<<sofar<<endl;
                paths.insert(sofar);
            }

        return paths.size();
        
    }
};