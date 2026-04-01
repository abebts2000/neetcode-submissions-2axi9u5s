class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        int cnt =0;

        if(s1.length() > s2.length())
            return false;
        for(int i =0;i<s1.length();i++)
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        
        for(int i =0;i<26;i++)
        {
            if(v1[i]==v2[i])
            {
                cnt++;
            }
        }
        if(cnt==26)
            return true;
        int l = s1.length();
        for(int i=s1.length();i<s2.length();i++)
        {
            if(v2[s2[i-l]-'a'] == v1[s2[i-l]-'a'])
                cnt--;
            v2[s2[i-l]-'a']--;
            if(v2[s2[i-l]-'a'] == v1[s2[i-l]-'a'])
                cnt++;
            if(v2[s2[i]-'a'] == v1[s2[i]-'a'])
                cnt--;
            v2[s2[i]-'a']++;
            if(v2[s2[i]-'a'] == v1[s2[i]-'a'])
                cnt++;
            if(cnt==26)
                return true;
            
            
        }

        return false;
    }
};
