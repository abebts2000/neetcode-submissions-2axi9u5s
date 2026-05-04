class Solution {
public:
    string getHash(string s)
    {
        if (s.empty()) return "";
        string res = "";
        int shift = s[0] - 'a';
        for(auto e : s)
        {
            res += (char)('a' + (e - 'a' - shift + 26) % 26);
        }
        return res;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> res;
        for(auto e : strings)
        {
            string key = getHash(e);
            res[key].push_back(e);
        }
        vector<vector<string>> output;
        for(auto& [key, values] : res)
        {
            output.push_back(values);
        }
        return output;

    }
};
