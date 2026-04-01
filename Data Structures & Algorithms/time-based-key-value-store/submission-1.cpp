class TimeMap {
private:
    std::unordered_map<string,vector<pair<string,int>>>dict;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dict[key].push_back(make_pair(value,timestamp));
    }
    
    string get(string key, int timestamp) {

        if(dict.find(key) == dict.end())
            return "";
        auto res = dict[key];
        string ans = "";
        int l =0,hi = res.size()-1;
        while(l<=hi)
        {
            int mid = l+(hi-l)/2;
            if(res[mid].second > timestamp)
            {
                hi=mid-1;
            }
            else
            {
                ans = res[mid].first;
                l=mid+1;
            }
        }
        return ans;
        
    }
};
