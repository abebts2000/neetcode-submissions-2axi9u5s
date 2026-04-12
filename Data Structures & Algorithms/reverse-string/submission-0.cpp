class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int st =0,end=s.size()-1;st<=end;st++,end--)
        {
            char t = s[st];
            s[st] = s[end];
            s[end] = t;
        }
    }
};