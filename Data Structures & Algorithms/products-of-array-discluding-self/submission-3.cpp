class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>forward(nums.size()+1,1),backward(nums.size()+1,1);
        int mult =1;
        for(int i =1;i<=nums.size();i++)
        {
            forward[i] = nums[i-1]*forward[i-1];
        }
        for(int i =nums.size()-2;i>=0;i--)
        {
            backward[i] = nums[i+1]*backward[i+1];
        }
        vector<int>ans(nums.size());
        for(int i =0;i<nums.size();i++)
        {
            ans[i] = forward[i]*backward[i];
        }
        return ans;
    }
};
