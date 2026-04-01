class Solution {
public:
    
    void generate(int n, string sofar, int lc, int rc, vector<string>&res)
    {
        if(sofar.length() ==2*n)
        {
            res.push_back(sofar);
            return;
        }
        if(lc < n)
        {
            generate(n,sofar+'(',lc+1,rc,res);
        }
        if(rc < lc)
        {
            generate(n,sofar+')',lc,rc+1,res);
        }

    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generate(n,"",0,0,res);
        return res;
        
    }
};
