class Solution {
public:
    vector<int> countBits(int n) {

        auto fn = [&](int n)
        {
            int c =0;
            while(n>0)
            {
                c+= n&1;
                n=n>>1;
            }
            return c;
        };
        vector<int>res;
        for(int i =0;i<=n;i++)
            res.push_back(fn(i));
       
        return res;
    }
};
