class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>mp;
        for(auto e:nums)
        {
            if(mp.find(e) != mp.end())
                return true;
            mp.insert(e);
        }
        return false;
    }
};