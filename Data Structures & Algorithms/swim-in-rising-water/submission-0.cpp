class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<pair<int, int>>> mp;
        unordered_map<int, int> dist;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int cell = i*n + j;
                dist[cell] = numeric_limits<int>::max();
                vector<vector<int>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
                for(auto e : dir) {
                    int x = i+e[0], y = j+e[1];
                    if(x>=0 && y>=0 && x<n && y<n) {
                        int cell2 = x*n + y;
                        mp[cell].push_back({cell2, grid[x][y]});
                    }
                }
            }
        }
        auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        
        dist[0] = grid[0][0];
        pq.push({0, dist[0]});
        
        int cellL = n*n - 1;
        while(!pq.empty()) {
            pair<int,int> top = pq.top();
            pq.pop();

            if(top.second > dist[top.first]) continue;
            if(top.first == cellL) return top.second;
           
            for(auto& e : mp[top.first]) {
                int next_dist = max(top.second, e.second);
                if(next_dist < dist[e.first]) {
                    dist[e.first] = next_dist;
                    pq.push({e.first, next_dist});
                }
            }
        }
        return -1;
    }
};