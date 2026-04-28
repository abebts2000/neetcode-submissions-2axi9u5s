class Solution {
public:
    string longestPalindrome(string s) {
        //start in the middle
        //start with two middle
        int st=0,end=0;
        for(int i=0;i<s.length();i++)
        {
            int l=i,r=i;
            while(l>=0 && r < s.length() && s[l] == s[r])
            {
                if(r-l > end-st)
                    end=r,st=l;
                l--,r++;
            }
            
        }
        for(int i=1;i<s.length();i++)
        {
            int l=i-1,r=i;
            while(l>=0 && r < s.length() && s[l] == s[r])
            {
                if(r-l > end-st)
                    end=r,st=l;
                l--,r++;
            }
            
        }

        return s.substr(st,end-st+1);

    }
};
