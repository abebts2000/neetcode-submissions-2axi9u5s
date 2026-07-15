class Solution {
public:
    bool isValid(const string &s)
    {
        if(s.length() == 0)
            return false;
        int last = s.length()-1;
        if((s[0] =='a' || s[0] =='e' ||s[0] =='i' || s[0] =='o' ||s[0] =='u')&&
            (s[last] =='a' || s[last] =='e' ||s[last] =='i' || s[last] =='o' ||s[last] =='u'))
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>prefix(words.size()+1,0),suffix(words.size()+1,0);
        int sum =0;
        for(int i =0;i<words.size();i++)
        {
            if(isValid(words[i]))
            {
                sum++;
            }
            prefix[i+1] = sum;
        }
        // sum =0;
        // for(int i =words.size()-1;i>=0;i--)
        // {
        //     if(isValid(words[i])
        //     {
        //         sum++;
        //     }
        //     suffix[i] = sum;
        // }
        vector<int>res;
        for(auto e:queries)
        {
            res.push_back(prefix[e[1] + 1] - prefix[e[0]]);
        }
        return res;
    }
};