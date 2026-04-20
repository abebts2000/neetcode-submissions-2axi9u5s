class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<vector<int>>T(coins.size(),vector<int>(amount+1,amount + 1));
        for(int c =0;c<coins.size();c++)
        {
            T[c][0] = 0;
            for(int i =1;i<=amount;i++)
            {
                if(i<coins[c])
                    T[c][i] = (c > 0) ? T[c-1][i] : amount + 1;
                else
                {
                    if(c>0)
                        T[c][i] = min(T[c-1][i], 1+T[c][i-coins[c]]);
                    else
                        T[c][i] = 1+T[c][i-coins[c]];
                }
            }
        }
        int mn = T[coins.size() - 1][amount];
        return mn > amount ? -1 : mn;
    }
};