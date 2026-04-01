class Solution {
public:
    
    string minWindow(string s, string t) {
        int st=0,end=0;
        unordered_map<char,int>ds,dt;
        int beg=-1,last=numeric_limits<int>::max();
        int need=0;
        for(auto e:t) {
            need++;
            dt[e]++;
        }
        int current_have = 0;
        while(end<s.length())
        {
           if(dt.find(s[end]) != dt.end())
           {
                ds[s[end]]++;
                if(ds[s[end]] <= dt[s[end]])
                {
                    current_have++;
                    need--;
                }
           }
            while(need == 0)
            {
                if(end-st < (long long)last-beg)
                    beg = st,last = end;
                if(dt.find(s[st]) != dt.end())
                {
                    if(ds[s[st]] <= dt[s[st]])
                    {
                        current_have--;
                        need++;
                    }
                    ds[s[st]]--;
                }
                st++;
            }
            end++;
        }
        return beg == -1 ? "" : s.substr(beg,last-beg+1);
    }
};