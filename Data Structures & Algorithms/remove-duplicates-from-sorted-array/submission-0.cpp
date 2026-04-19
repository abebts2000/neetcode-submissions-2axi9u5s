class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0,r=1;
        for(;r<nums.size();r++ )
        {
            if(nums[r] == nums[l])
                continue;
            else
            {
                nums[l+1] = nums[r];
                l++;
            }
        }
        return l+1;
    }
};