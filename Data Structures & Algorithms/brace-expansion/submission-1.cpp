class Solution {
public:
    void expand(string s, int indx, string sofar, vector<string>&res)
    {
        if(indx >= s.length())
        {
            res.push_back(sofar);
            return;
        }
        if(s[indx] == '{')
        {
            int curl = s.find('}',indx);
            indx++;
            while(s[indx] != '}')
            {
                if(s[indx] != ',')
                {
                    expand(s,curl+1,sofar+s[indx],res);
                }
                indx++;
            }
        }
        else
            expand(s,indx+1,sofar+s[indx],res);
    }
    vector<string> expand(string s) {
        vector<string>res;
        expand(s,0,"",res);
        return res;
    }
};
