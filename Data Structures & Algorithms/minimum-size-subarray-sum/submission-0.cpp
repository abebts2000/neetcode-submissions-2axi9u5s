class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l =0,r=0,res = numeric_limits<int>::max();
        int total = 0;
        for(;r<nums.size();r++)
        {
            total += nums[r];
            while(total >= target)
            {
                res = min(res,r-l+1);
                total-=nums[l];
                l++;
            }
        }
        return res == numeric_limits<int>::max()?0:res;

    }
};