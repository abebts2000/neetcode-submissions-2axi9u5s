class Solution {
public:
    int dfs(const vector<vector<int>>& matrix, vector<vector<int>>& cache, int r, int c, int prev)
    {
        if(r < 0 || c < 0 || r>= matrix.size() || c >= matrix[0].size() || matrix[r][c] <= prev)
            return 0;
        if(cache[r][c] == -1)
        {
            int len =1;
            vector<vector<int>>dir = {{0,-1},{-1,0},{0,1},{1,0}};
            for(auto e:dir)
            {
                len = max(len, 1+ dfs(matrix,cache,r+e[0],c+e[1],matrix[r][c]));
            }
            cache[r][c] = len;
        }
        return cache[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
       vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(),-1));
       int lp =0;

       for(int i=0;i<matrix.size();i++)
       {
        for(int j =0;j<matrix[0].size();j++)
        {
            lp = max(lp,dfs(matrix,cache, i,j,numeric_limits<int>::min()));
        }
       }
       return lp;
    }
};
