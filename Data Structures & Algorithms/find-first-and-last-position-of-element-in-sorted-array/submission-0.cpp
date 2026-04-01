class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l =0,h=nums.size()-1;
        int left=-1,right=-1;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(nums[mid] < target)
            {
                l=mid+1;
            }
            else if(nums[mid] > target)
            {
                h=mid-1;
            }
            else
            {
                left = mid;
                h=mid-1;
            }
        }
        if(left != -1)
        {
            l=left,h=nums.size()-1;
            while(l<=h)
            {
                int mid = l+(h-l)/2;
                if(nums[mid] < target)
                {
                    l=mid+1;
                }
                else if(nums[mid] > target)
                {
                    h=mid-1;
                }
                else
                {
                    right = mid;
                    l=mid+1;
                }
            }
        }
        return {left,right};
    }
};