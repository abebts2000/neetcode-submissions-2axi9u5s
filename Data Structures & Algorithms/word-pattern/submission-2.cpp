class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }

        if(words.size() != pattern.length())
            return false;
        unordered_map<string,char>dict;
        string pattern2 = "";
        for(int i =0;i<words.size();i++)
        {
            if(dict.find(words[i]) != dict.end())
            {
                if(pattern[i] != dict[words[i]])
                    return false;
            }
            else
            {
                dict[words[i]] = pattern[i];
            }

        }
        unordered_map<char,string>dict2;
        for(int i =0;i<words.size();i++)
        {
            if(dict2.find(pattern[i]) != dict2.end())
            {
                if(words[i] != dict2[pattern[i]])
                    return false;
            }
            else
            {
                dict2[pattern[i]] = words[i];
            }

        }
        return true;

    }
};