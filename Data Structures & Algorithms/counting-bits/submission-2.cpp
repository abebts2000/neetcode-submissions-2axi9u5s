class Solution {
public:

    vector<int> countBits(int n) {

        unordered_map<int,int>cnt= {{0,0},{1,1},{2,1},{3,2},{4,1},{5,2},{6,2},{7,3}};
        auto fnby3 = [&](int n)
        {
            int c =0;
            while(n>0)
            {
                int msk = 0x7;
                int temp = msk&n;
                c+=cnt[temp];
                n=n>>3;
            }
            return c;
        };

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
            //res.push_back(fn(i));
            res.push_back(fnby3(i));
       
        return res;
    }
};
