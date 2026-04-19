class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        for(int i=0;i<obstacleGrid.size();i++)
        {
            for(int j =0;j<obstacleGrid[0].size();j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if(i==0 && j==0 && obstacleGrid[i][j] == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = (i>0?dp[i-1][j]:0) + (j>0?dp[i][j-1]:0);
                    
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];

    }
};