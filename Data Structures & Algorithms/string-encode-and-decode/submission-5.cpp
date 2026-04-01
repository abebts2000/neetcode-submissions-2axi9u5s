class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() ==0)
            return "";
        string res = "";
        for(auto e:strs)
        {
            res += e + '\0';
        }
        std::cout<<res<<endl;
        return res;
    }

    vector<string> decode(string s) {
        char sep = char(257);
        if(s.length() ==0)
            return {};
        vector<string>res;
        string temp = "";
        for(auto e:s)
        {
            if(e!='\0')
                temp +=e;
            else
            {
                res.push_back(temp);
                temp = "";
            }
        }
        
        return res;

    }
};
