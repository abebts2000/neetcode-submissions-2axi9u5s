class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.length() + 1, s.length());
        dp[0] = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i < s.length()) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            for (auto e : dictionary) {
                if (i + e.length() <= s.length() && s.substr(i, e.length()) == e) {
                    dp[i + e.length()] = min(dp[i + e.length()], dp[i]);
                }
            }
        }
        return dp[s.length()];
    }
};