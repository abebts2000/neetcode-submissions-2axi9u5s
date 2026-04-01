class Solution {
public:
    void dfs(string digits, int indx, string sofar, unordered_map<char,vector<char>>&dict,vector<string>&res)
    {
        if(indx == digits.length() && sofar.length()>0)
        {
            res.push_back(sofar);
            return;
        }
        for(auto e:dict[digits[indx]])
        {
            dfs(digits,indx+1,sofar+e,dict,res);
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        unordered_map<char,vector<char>>dict =   {{'2',{'a','b','c'}},{'3',{'d','e','f'}},
                                                {'4',{'g','h','i'}},{'5',{'j','k','l'}},
                                                {'6',{'m','n','o'}},{'7',{'p','q','r','s'}},
                                                {'8',{'t','u','v'}},{'9',{'w','x','y','z'}}
                                                };
        dfs(digits,0,"",dict,res);
        return res;
    }
};
