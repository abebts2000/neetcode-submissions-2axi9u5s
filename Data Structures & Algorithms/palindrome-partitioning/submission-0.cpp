class Solution {
public:

    bool isPalindrome(const string& s)
    {
        for(int l =0,r = s.length()-1;l<=r;l++,r--)
        {
            if(s[l] != s[r])
                return false;
        }
        return true;
    }

    void DFS(string &s, int indx, vector<string>sofar, string last, vector<vector<string>>&res)
    {
        if(indx >= s.length() )
        {
            if(isPalindrome(last) && last.length() > 0)
            {
                sofar.push_back(last);
                res.push_back(sofar);
            }
            return;
        }

        if(isPalindrome(last) && last.length()>0)
        {
            sofar.push_back(last);
            string newlast= "";
            DFS(s,indx+1,sofar,newlast+s[indx],res);
            sofar.pop_back();
        }
        DFS(s,indx+1,sofar, last+s[indx],res);
    }
    vector<vector<string>> partition(string s) {
        //you can start new substring
        //continue including this character and hope you can make another palindrom
        vector<vector<string>>res;
        DFS(s,0,{}, "",res);
        return res;
    }
};
