class Solution {
public:
    bool DFS(int course,unordered_map<int,vector<int>>&dict,unordered_set<int>&visited,unordered_set<int>&visiting )
    {
        if(visiting.find(course) != visiting.end())
            return false;
        if(visited.find(course) != visited.end())
            return true;
        visiting.insert(course);
        for(auto e:dict[course])
        {
            if(!(DFS(e,dict,visited,visiting)))
                return false;
        }
        visiting.erase(course);
        visited.insert(course);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>dict;
        for(auto e:prerequisites)
        {
            dict[e[0]].push_back(e[1]);
        }
        unordered_set<int>visited;
        for(int  i =0;i<numCourses;i++)
        {
            if(visited.find(i) == visited.end())
            {
                unordered_set<int>visiting;
                if(!DFS(i,dict,visited,visiting))
                    return false;
            }
        }
        return true;
    }
};
