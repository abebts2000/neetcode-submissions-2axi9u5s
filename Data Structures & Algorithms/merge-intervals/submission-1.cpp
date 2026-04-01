class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),intervals.end());
        auto prev = intervals[0];
        vector<vector<int>>res;
        for(auto e:intervals)
        {
            if(e[0] > prev[1])
            {
                res.push_back(prev);
                prev = e;
            }
            else
            {
                prev = {min(prev[0],e[0]), max(prev[1],e[1])};
            }
        }
        res.push_back(prev);
        return res;
    }
};
