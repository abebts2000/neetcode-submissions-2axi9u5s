class Solution {
public:
    vector<int>prefix;
    Solution(vector<int>& w) {
        // prefix.push_back(0);
        int sum =0;
        for(auto wgt:w)
        {
            sum += wgt;
            prefix.push_back(sum);
            
        }
    }
    
    int pickIndex() {
        int target = prefix.back() * ((double) rand() / RAND_MAX);
        int l=0, r = prefix.size() - 1;

        while( l < r)
        {
            int mid = l+(r-l)/2;
            if(prefix[mid] <= target)
                l = mid+1;
            else
                r = mid;
        }
        return l;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */