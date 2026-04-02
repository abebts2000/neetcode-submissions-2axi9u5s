class Solution {
public:
    bool isValidFull(string s)
    {
        stack<char>stk;
        for(auto e:s)
        {
            if(e=='(')
                stk.push(e);
            else
            {
                if(stk.empty())
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
    bool isValid(const string& s, string newFormed, int indx)
    {
        if (indx == s.length())
            return isValidFull(newFormed);

        //replace * with either ( or ) or skip
        bool  check = false;
        if(s[indx] == '*')
        {
            return isValid(s,newFormed+'(',indx+1)||isValid(s,newFormed+')',indx+1)||isValid(s,newFormed,indx+1);
        }
        else
            return isValid(s,newFormed+s[indx],indx+1);

    }

    int memo[101][101];
    bool dfs(const string& s, int open, int indx)
    {        
        if(open < 0)
            return false;
        if(indx == s.length())
            return open ==0;
        if(memo[indx][open] != -1)
            return memo[indx][open];
        
        bool res;
        if(s[indx] == '(')
            res = dfs(s,open+1,indx+1);
        else if (s[indx] == ')')
            res = dfs(s,open-1,indx+1);
        else
            res = dfs(s,open+1,indx+1)||dfs(s,open-1,indx+1)||dfs(s,open,indx+1);
        
        return memo[indx][open] = res;
    }
    bool checkValidString(string s) {
        for(int i=0; i<101; i++) 
            for(int j=0; j<101; j++) 
                memo[i][j] = -1;
        return dfs(s,0,0);
        //return isValid(s,"",0);
    }
};
