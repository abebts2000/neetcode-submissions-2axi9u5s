class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int mx =0,st=0,end=0,cnt=0;
        for(auto e:s)
        {
            mp[e]++;
            if(mp[e] > cnt)
            {
                cnt = mp[e];
            }
            while(end -st +1- cnt > k)
            {
                mp[s[st]]--;
                st++;
            }
            mx = max(mx,end-st+1);
            end++;
        }
        // if(end -st - mp[s.back()] <=k)
        // {
        //     mx = max(mx,end-st);
        // }
        return mx;
    }
};
