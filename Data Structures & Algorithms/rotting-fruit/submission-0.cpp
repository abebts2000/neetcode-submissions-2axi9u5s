class Solution {
public:


    int orangesRotting(vector<vector<int>>& grid) {
        //use queue.. each minute pop all rotten ones and add neighbpring fresh ones as rotten
        //continue till queue is empty
         queue<pair<int, int>> q;
        int fresh = 0;
        int minutes = 0;
        
        // First pass: count fresh oranges and add rotten ones to queue
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }
        
        // Directions: up, down, left, right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // BFS
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            
            // Process all oranges that are rotten at this minute
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                // Check all 4 directions
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;
                    
                    // If neighbor is fresh, make it rotten
                    if (nr >= 0 && nr < grid.size() && 
                        nc >= 0 && nc < grid[0].size() && 
                        grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        
        return fresh == 0 ? minutes : -1;

    }
};
