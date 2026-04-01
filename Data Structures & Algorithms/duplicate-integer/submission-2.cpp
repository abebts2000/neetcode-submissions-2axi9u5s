class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto e:nums)
        {
            if(mp.find(e) != mp.end())
                return true;
            mp[e]++;
        }
        return false;
    }
};