class Solution {
public:
    int numDigits(int x)
    {
        if (x == 0) return 1;
        long long temp = abs((long long)x);
        int c = 0;
        while(temp > 0)
        {
            c++;
            temp /= 10;
        }
        return c;
    }
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int digits = numDigits(x);
        long long tempX = x;
        digits -= 1;
        while(tempX > 0 && digits > 0)
        {
            int rem = tempX % 10;
            long long p = pow(10, digits);
            int div = tempX / p;
            
            if(rem != div)
                return false;
            
            tempX = (tempX % p) / 10;
            digits -= 2;
        }
        return true;
    }
};