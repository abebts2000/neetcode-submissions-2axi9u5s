class Solution {
public:
    void DFS(int cur, unordered_map<int,vector<int>>&dict, unordered_set<int>&st)
    {
        if(st.find(cur) == st.end())
            st.insert(cur);
        else
            return;
        for(auto e:dict[cur])
            DFS(e,dict,st);

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>dict;
        for(auto e:edges)
        {
            dict[e[0]].push_back(e[1]);
            dict[e[1]].push_back(e[0]);
        }
        int c =0;
        unordered_set<int>st;
        for(int i =0;i<n;i++)
        {
            if(st.find(i) == st.end())
            {
                c++;
                DFS(i,dict,st);
            }

        }
        return c;

    }
};
