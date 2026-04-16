class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = string(word1.length()+word2.length(),' ');
        int i =0;
       for(int i =0,j=0,c=0;c<res.length();)
       {
            if(i<word1.length())
                res[c] = word1[i],c++,i++;
            if(j<word2.length())
                res[c] = word2[j],c++,j++;
       } 
        return res;

    }
};