class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp = [x](int a, int b)
        {
            if(abs(a-x) == abs(b-x))
                return a < b;
            return abs(a-x) < abs(b-x);
        };

        priority_queue<int,vector<int>,decltype(cmp)>pq(cmp);

        for(auto e:arr)
        {
            pq.push(e);
            if(pq.size() > k)
            pq.pop();
        }

        vector<int>res;
        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;

    }
};