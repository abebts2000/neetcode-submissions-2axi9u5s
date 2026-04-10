class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,pair<int,int>>parent;
        unordered_map<int,vector<pair<int,int>>> edges;
        int t = 0;
        for(auto &edge : times)
        {
            int src = edge[0], dest = edge[1], len = edge[2];
            edges[src].push_back({dest,len});
            parent[src] = {src,-1};
            parent[dest] = {dest,-1};
        }
        auto cmp = [](pair<int,int> a ,pair<int,int> b)
        {
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>,decltype(cmp)>pq(cmp);

        pq.push({k,0});
        unordered_set<int>st;
        while(!pq.empty())
        {
            auto [node,time] = pq.top();
            pq.pop();
            if(st.find(node) != st.end())
                continue;
            st.insert(node);
            t=time;
            for(auto &[node2,len2]:edges[node])
            {
                if(st.find(node2) == st.end())
                {
                    pq.push({node2,time+len2});
                }
            }

        }

        return st.size()==n?t:-1;

    }
};
