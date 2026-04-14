class Solution {
public:
    int numDecodings(string s) {
        unordered_map<string,char>mp;
        for(int i =0;i<26;i++)
        {
            mp[to_string(i+1)] = 'A'+i;
        }
        vector<int>dp(s.length()+1);
        dp[s.size()] = 1;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='0')
                dp[i] = 0;
            else
            {
                dp[i] = dp[i+1];//single digit
                if(i+1 < s.size() && (s[i] == '1' ||  s[i] =='2' && s[i+1] < '7'))
                {
                    dp[i] += dp[i+2]; //two digit
                }
            }
        }
        return dp[0];

    }
};
