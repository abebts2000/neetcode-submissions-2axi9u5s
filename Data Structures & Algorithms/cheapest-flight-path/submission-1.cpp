class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto e:flights)
        {
            mp[e[0]].push_back({e[1],e[2]});
        }

        auto cmp = [](pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b)
        {
            return a.first.second > b.first.second;
        };
        
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,decltype(cmp)>pq(cmp);

        pq.push({{src,0},0});
        unordered_set<int>st;
        //st.insert(src);
        while(!pq.empty())
        {
            auto [node,level] = pq.top();
            pq.pop();
            if(level > k+1)
                continue;
            if(node.first == dst)
                return node.second;
            for(auto e:mp[node.first])
            {
                //if(st.find(e.first) == st.end())
                {
                    //st.insert(e.first);
                    pq.push({{e.first, node.second+e.second},level+1});
                }
            }

        }
        return -1;


    }
};
