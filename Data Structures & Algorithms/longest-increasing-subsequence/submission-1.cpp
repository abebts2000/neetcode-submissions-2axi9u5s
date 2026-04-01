class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>T(nums.size(),1);
        int mx =1;
        for(int i =1;i<nums.size();i++)
        {
            for(int j = i-1;j>=0;j--)
            {
                if(nums[j] < nums[i])
                    T[i] = max(T[i], 1+T[j]);
            }
            mx= max(mx,T[i]);
        }
        return mx;
    }
};
