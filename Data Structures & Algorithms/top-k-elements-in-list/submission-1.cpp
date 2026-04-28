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
        for(auto e:mp)
        {
            pq.push(e);
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
