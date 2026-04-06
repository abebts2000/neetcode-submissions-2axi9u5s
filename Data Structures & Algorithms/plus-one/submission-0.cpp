class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>res(digits.size()+1);
        int c =1;
        res[0] = 1;
        for(int i =digits.size()-1;i>=0;i--)
        {
            int sum = digits[i]+c;
            c = sum/10;
            digits[i] = sum%10;
            res[i+1] = sum%10;
        }

        if(c==0)
            return digits;
        else
            return res;

    }
};
