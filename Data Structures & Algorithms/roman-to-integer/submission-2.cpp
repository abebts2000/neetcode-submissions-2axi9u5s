class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>dict = {{'I',1},{'V',5}, {'X',10},{'L',50}, {'C',100},{'D',500}, {'M',1000}};
        int res =0;
        for(int i=0;i<s.length();i++)
        {
            char prev = s[i];
            if(i+1 < s.length() && dict[prev] < dict[s[i+1]])
                res += (-dict[prev]);
            else
                res += (dict[prev]);
        }
       
        return res;
    }
};