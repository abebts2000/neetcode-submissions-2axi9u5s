class Solution {
public:
    int mySqrt(int x) {
        double delta = 0.00001;
        //double l = 0.0, h = (double)x;
        long long l=0,h=x;
        int ans = 0;
        while(l<=h)
        {
            long long mid = l+(h-l)/2;
            long long res = mid*mid;
            if(res == x)
            {
                return mid;
            }
            else if(res < x)
            {
                ans = mid;
                l =mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
        return ans;
    }
};