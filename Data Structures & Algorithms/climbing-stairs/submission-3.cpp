class Solution {
public:

    int climb(int n, vector<int>&cache)
    {
        if(n<=2)
            cache[n] = n;
        if(cache[n] == -1)
        {
            cache[n] = climb(n-1,cache)+climb(n-2,cache);
        }
        return cache[n];
    }
    int climbStairs1(int n) {
        if(n <= 2)
            return n;
        else
            return climbStairs(n-1)+ climbStairs(n-2);
        
    }
    int climbStairs(int n) {
        vector<int>T(n+1,-1);
        climb(n,T);
        return T[n];
    }
};
