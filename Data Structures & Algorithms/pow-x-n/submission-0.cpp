class Solution {
public:
    double pow(double x, int n, unordered_map<int,double>&mp)
    {
        if(n==0)
            return 1.0;
        if(n==1)
            return x;
        if(mp.find(n) == mp.end())
        {
            double val = pow(x,n/2,mp);
            mp[n] = n%2==0?val*val:x*val*val;
        }
        return mp[n];
        
    }
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        unordered_map<int,double>mp;
        if(n < 0)
            return 1.0 / pow(x, -(long long)n, mp);
        return pow(x, n, mp);
    }

};