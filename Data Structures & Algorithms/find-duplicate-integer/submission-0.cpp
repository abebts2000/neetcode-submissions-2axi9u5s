class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto e:nums)
        {
            int indx = abs(e)-1;
            if(nums[indx] < 0)
                return abs(e);
            nums[indx]*= -1;
        }
        return -1;
    }
};
