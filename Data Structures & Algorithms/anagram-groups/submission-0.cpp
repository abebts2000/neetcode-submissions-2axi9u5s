class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
       for(auto e:strs)
       {
        string temp = e;
        std::sort(temp.begin(),temp.end());
        mp[temp].push_back(e);
       } 

       vector<vector<string>>res;
       for(auto e:mp)
       {
        res.push_back(e.second);
       }
       return res;
    }
};
