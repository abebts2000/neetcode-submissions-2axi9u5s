class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.length()+1,false);
        dp[s.length()] = true;
        for(int i=s.length()-1;i>=0;i--)
        {
            for(const auto&e:wordDict)
            {
                if(i+e.length()<=s.length() && e==s.substr(i,e.length()))
                {
                    dp[i] = dp[i+e.length()];
                    if(dp[i])
                        break;
                }
            }
        }
        return dp[0];
    }
};
