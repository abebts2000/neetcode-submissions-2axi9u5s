class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //start with st and last.. when we enciounter visited then we stop and check.. we move to when the duplicate indx is
        int st=0,end=0;
        int len =0;

        unordered_map<char,int>mp;
        for(;end<s.length();end++)
        {
            if(mp.find(s[end]) == mp.end() || (mp.find(s[end]) != mp.end() && mp[s[end]] < st))
            {
                mp[s[end]] = end;
                len = max(len,end-st+1);
            }
            else
            {
                len = max(len,end-st);
                st = mp[s[end]]+1;
                mp[s[end]] = end;
            }
        }
        return len;
    }
};
