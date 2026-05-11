class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<tuple<int,int,bool>>pts;
        for(auto e:trips)
        {
            pts.push_back({e[1],e[0],true});
            pts.push_back({e[2],e[0],false});
        }
        sort(pts.begin(),pts.end(),[](const tuple<int,int,bool>&a, const tuple<int,int,bool>&b)
        {
            if(get<0>(a) != get<0>(b))
                return get<0>(a) < get<0>(b);
            return get<2>(a) < get<2>(b);
        });

        stack<tuple<int,int,bool>>stk;
        int available = capacity;
        for(auto e:pts)
        {
            if(get<2>(e))
            {
                if(available < get<1>(e))
                    return false;
                available -= get<1>(e);
            }
            else
            {
                available += get<1>(e);
            }
        }
        return true;

    }
};