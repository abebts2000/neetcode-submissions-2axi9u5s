class Solution {
public:
    int compress(vector<char>& chars) {
        char prev = chars[0];
        int c =0;
        string s ="";
        for(auto e:chars)
        {
            //cout<<"prev:"<<prev<<" cur:"<<e<<" count:"<<c<<endl;
            if(e == prev)
                c++;
            else
            {
                s+=prev;
                if(c>1)
                    s += to_string(c);
                c =1;
            }
            prev = e;
        }
        s+=prev;
        if(c>1)
            s += to_string(c);
        chars = {};
        for(auto ch:s)
            chars.push_back(ch);
        return s.length();
    }
};