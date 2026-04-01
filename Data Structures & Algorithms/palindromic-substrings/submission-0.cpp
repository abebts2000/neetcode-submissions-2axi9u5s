class Solution {
public:
    int countSubstrings(string s) {
        int count =0;
        //even length
        for(int indx = 0;indx < s.length();indx++)
        {
            int i = indx, j=indx+1;
            while(i>=0 && j < s.length() && s[i] == s[j])
            {
                count++;
                i--;
                j++;
            }    

        }
        //odd length
        for(int indx = 0;indx < s.length();indx++)
        {
            int i = indx, j=indx;
            while(i>=0 && j < s.length() && s[i] == s[j])
            {
                count++;
                i--;
                j++;
            }    

        }
        return count;
    }
};
