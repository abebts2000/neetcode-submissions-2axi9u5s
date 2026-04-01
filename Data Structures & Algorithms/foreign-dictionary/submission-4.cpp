class Solution {
public:

    bool DFS(char ch,unordered_map<char,vector<char>>&dict, unordered_set<char>&visited, unordered_set<char>&visiting,string& res)
    {
        if(visiting.find(ch) != visiting.end())
            return false;
        if(visited.find(ch) != visited.end())
            return true;
        visiting.insert(ch);
        for(auto e:dict[ch])
        {
            if(!DFS(e,dict,visited,visiting,res))
                return false;
        }
        res+=ch;
        visited.insert(ch);
        visiting.erase(ch);
        return true;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>>dict;
        string prev = words[0];
        for(auto e:words)
            for(auto g:e)
                dict[g];
        for(auto e:words)
        {
            int minLen = min(prev.length(),e.length());
            if(prev.length() > e.length() && prev.substr(0,minLen) == e.substr(0,minLen))
                return "";
            for(int i =0;i<prev.length()&&i<e.length();i++)
            {
                if(prev[i] != e[i])
                {
                    dict[prev[i]].push_back(e[i]);
                    break;
                }
            }
            prev = e;
        }
        unordered_set<char>visited;
        string res;
        for(auto e:dict)
        {
            unordered_set<char>visiting;
            if(!DFS(e.first,dict,visited,visiting,res))
                return "";
        }
        reverse(res.begin(), res.end());

        return res;

    }
};
