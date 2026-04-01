class Solution {
public:
    long long squareandSum(int n)
    {
        long long sum =0;
        while(n>0)
        {
            int rem = n%10;
            sum += rem*rem;
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<long long>st;

        long long res = squareandSum(n);
        
        while(true)
        {
            if(res == 1)
                return true;
            if(st.find(res) != st.end())
                return false;
            st.insert(res);
            res = squareandSum(res);
        }
        return true;
        
    }
};
