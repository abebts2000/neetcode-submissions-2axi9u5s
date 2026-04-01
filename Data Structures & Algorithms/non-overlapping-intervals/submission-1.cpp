class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),intervals.end(), [](const vector<int>&a,const vector<int> &b)
        {
            return a[1] < b[1];
        });

        int rem =0;
        int prevEnd = numeric_limits<int>::min();
        for(auto e:intervals)
        {
            int start = e[0], end = e[1];
            if(start < prevEnd)
                rem++;
            else
                prevEnd = end;
        }
        return rem;

    }
};
