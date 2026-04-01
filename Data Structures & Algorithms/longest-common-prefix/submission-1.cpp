class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int indx = strs[0].length()-1;
        for(int i =1;i<strs.size();i++)
        {
            int j =0;
            while(strs[i][j] == strs[i-1][j] && j <= indx)
                j++;
            indx = min(indx,j-1);
        }
        return strs[0].substr(0,indx+1);
    }
};