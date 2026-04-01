class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,hi=nums.size()-1;
        while(l<=hi)
        {
            int mid = l+(hi-l)/2;
            if(nums[mid] == target) return mid;
            
            if(nums[l] <= nums[mid])
            {
                if(target >= nums[l] && target < nums[mid])
                    hi = mid-1;
                else
                    l = mid+1;
            }
            else
            {
                if(target > nums[mid] && target <= nums[hi])
                    l = mid+1;
                else
                    hi = mid-1;
            }
        }
        return -1;
    }

};
