class Solution {
public:
    bool isalphanum(char c)
    {
        if((c-'a'>=0 && c-'a'<26) || (c-'A'>=0 && c-'A'<26) || (c-'0' >=0 && c-'0' <=9))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        for(int i =0,j=s.length()-1;i<j;)
        {
            if(!isalphanum(s[i]))
                i++;
            else if(!isalphanum(s[j]))
                j--;
            else
            {
                if(tolower(s[i]) != tolower(s[j]))
                    return false;
                i++,j--;
            }

        }
          return true;  

    }
};