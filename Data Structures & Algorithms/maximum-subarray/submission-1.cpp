class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>T(nums.size());
        int mx = nums[0];
        T[0] = nums[0];
        for(int i =1;i<nums.size();i++)
        {
            T[i] = max(nums[i]+T[i-1],nums[i]);
            mx= max(mx,T[i]);
        }
        return mx;
            
    }
};
