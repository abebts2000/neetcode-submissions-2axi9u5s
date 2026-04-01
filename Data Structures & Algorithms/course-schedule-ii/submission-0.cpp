class Solution {
public:
    bool DFS( int course, unordered_map<int,vector<int>>&dict,unordered_set<int>&visiting,unordered_set<int>&visited, vector<int>&output)
    {
        if(visiting.find(course) != visiting.end())
            return false;
        if(visited.find(course) != visited.end())
            return true;
        visiting.insert(course);
        for(int pre : dict[course]) {
            if(!DFS(pre,dict,visiting,visited,output))
                return false;
        }
        visiting.erase(course);
        visited.insert(course);
        output.push_back(course);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>dict;
        unordered_set<int>visited;
        vector<int>output;
        for(auto e:prerequisites)
            dict[e[0]].push_back(e[1]);
        for(int i =0;i<numCourses;i++)
        {
            if(visited.find(i) == visited.end())
            {
                unordered_set<int>visiting;
                if(!DFS(i,dict,visiting,visited, output))
                    return {};
            }
        }
        return output;
    }
};