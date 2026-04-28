class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // auto comp = [](const pair<int,int>&a, const pair<int,int>&b){
        //     return a.second > b.second;
        // };
        // priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq2;
        unordered_map<int,int>mp;
        vector<int>res;
        for(auto e:nums)
        {
            mp[e]++;
        }
        for(auto e:mp)
        {
            //pq.push(e);
            pq2.push({e.second,e.first});
            // if(pq.size() > k)
            //     pq.pop();
            if(pq2.size() > k)
                pq2.pop();
        }
        // while(!pq.empty())
        // {
        //     res.push_back(pq.top().first);
        //     pq.pop();
        // }
        while(!pq2.empty())
        {
            res.push_back(pq2.top().second);
            pq2.pop();
        }
        return res;
    }
};
