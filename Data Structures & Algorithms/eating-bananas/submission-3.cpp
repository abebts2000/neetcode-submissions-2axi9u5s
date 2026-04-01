class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = piles[0];
        for(auto e:piles)
        {
            mx = max(mx,e);
        }
        int k = -1;
        int l=1,hi=mx;
        while(l<=hi)
        {
            int mid = l+(hi-l)/2;
            long long tot =0;
            for(auto e:piles)
            {
                tot += ceil(static_cast<double>(e)/mid);
            }
            if(tot <= h)
            {
                k = mid;
                hi = mid-1;
            }
            else
            {
                l=mid+1;
            }

        }
        return k;

    }
};
