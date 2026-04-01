class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto comp = [](const pair<int,int>&a, const pair<int,int>&b){
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        unordered_map<int,int>mp;
        vector<int>res;
        for(auto e:nums)
        {
            mp[e]++;
        }
        int c =0;
        for(auto e:mp)
        {
            if(c<k)
            {
                pq.push(e);
            }
            else
            {
                if(pq.top().second < e.second)
                {
                    pq.pop();
                    pq.push(e);
                }
            }
            c++;
        }
        while(!pq.empty())
        {
            auto top = pq.top();
            res.push_back(top.first);
            pq.pop();
        }
        return res;
    }
};
