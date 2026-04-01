class Solution {
public:
    int findMin(vector<int> &nums) {
        int l =0,hi=nums.size()-1;
        int mn = numeric_limits<int>::max();
        while(l <hi)
        {
            int mid = l+(hi-l)/2;

            //what if min is in left part
            if(nums[mid] > nums[hi])
                l = mid+1;
            else if(nums[mid] < nums[hi])
                hi = mid;
            //what if min is in right part

        }
        return nums[l];
    }
};
