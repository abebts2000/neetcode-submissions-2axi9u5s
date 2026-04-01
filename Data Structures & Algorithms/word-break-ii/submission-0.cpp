class Solution {
public:
    void DFS(string s, int indx, unordered_set<string>&dict, string sofar, vector<string>&res)
    {
        //cout<<sofar<<endl;
        if(indx > s.length())
            return;
        if(indx == s.length())
        {
            res.push_back(sofar);
            return;
        }
        for(auto e:dict)
        {
            //cout<<s.substr(indx, e.length())<<endl;
            if(indx+e.length() <= s.length() && s.substr(indx, e.length()) == e)
            {
                if(sofar.length() ==0)
                    DFS(s,indx+e.length(),dict,sofar+e,res);
                else
                    DFS(s,indx+e.length(),dict,sofar + " "+e,res);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        vector<string>res;
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        DFS(s,0,dict,"",res);
        return res;
    }
};