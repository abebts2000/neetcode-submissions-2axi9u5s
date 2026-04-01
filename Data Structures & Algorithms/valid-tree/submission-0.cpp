class Solution {
public:
    bool validTreehelper(int cur, int parent, unordered_map<int,vector<int>>& dict, unordered_set<int>&visited) {
        if(visited.find(cur) != visited.end())
            return false;
        visited.insert(cur);
        for(auto e:dict[cur])
        {
            if(e == parent) continue;
            if(!validTreehelper(e, cur, dict, visited))
                return false;
        }
        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        unordered_map<int,vector<int>> dict;
        for(auto e:edges)
        {
            dict[e[0]].push_back(e[1]);
            dict[e[1]].push_back(e[0]);
        }
        unordered_set<int>visited;
        if(!validTreehelper(0, -1, dict, visited))
            return false;
        return visited.size() == n;
    }
};
