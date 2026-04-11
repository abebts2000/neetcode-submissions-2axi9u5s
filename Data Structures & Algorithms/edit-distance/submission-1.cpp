class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>T(word1.length()+1,vector<int>(word2.length()+1));
        for(int i=0;i<=word1.length();i++)
        {
            T[i][0] = i;
            for(int j=1;j<=word2.length();j++)
            {
                if(i==0)
                    T[i][j] = j;
                else
                {
                    if(word1[i-1] == word2[j-1] )
                        T[i][j] = T[i-1][j-1];
                    else
                        T[i][j] = 1+min(T[i-1][j-1],min(T[i-1][j],T[i][j-1]));
                }

            }
        }
        return T[word1.length()][word2.length()];
    }
};
