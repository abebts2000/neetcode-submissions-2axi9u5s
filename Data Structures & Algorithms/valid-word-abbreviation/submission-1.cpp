class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0,j=0;
        for(;i<word.length();)
        {
            int num =0;
            if(abbr[j]-'0'>=0 && abbr[j]-'0' <=9)
            {
                if(abbr[j]-'0'==0)
                    return false;
                while((abbr[j]-'0' >=0) && (abbr[j]-'0' <=9) && j < abbr.length())
                {                    
                    num = num*10+(abbr[j]-'0');
                    j++;
                }
                i=i+num;
            }
            else
            {
                if(word[i] != abbr[j])
                    return false;
                j++;
                i++;
            }
        }
        return i==word.length()&&j==abbr.length();
    }
};