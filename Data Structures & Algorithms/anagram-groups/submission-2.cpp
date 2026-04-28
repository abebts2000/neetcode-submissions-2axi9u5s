class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
       for(auto word:strs)
       {
        string temp = word;
        std::sort(temp.begin(),temp.end());
        mp[temp].push_back(word);
       } 

       vector<vector<string>>res;
       for(const auto& [sorted,words]:mp)
       {
        res.push_back(words);
       }
       return res;
    }
};
