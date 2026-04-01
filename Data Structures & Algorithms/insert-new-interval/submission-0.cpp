class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        for(auto e:intervals)
        {
            if(e[1] < newInterval[0])
            {
               res.push_back(e); 
            }
            else if(e[0] > newInterval[1])
            {
                res.push_back(newInterval);
                newInterval = e;
            }
            else
            {
                newInterval[0] = min(newInterval[0],e[0]);
                newInterval[1] = max(newInterval[1],e[1]);
            }
        }
        if(res.size()==0 || newInterval[0] > res.back()[1] )
            res.push_back(newInterval);
        return res;
    }
};
