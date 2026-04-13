class Solution {
public:
    void reverse(vector<int>& nums,int l, int r)
    {
        while(l<=r)
        {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++,r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
      int size = (int)nums.size();
      k = k%size;
      reverse(nums, 0,size-k-1);
      reverse(nums,size-k,size-1);
      reverse(nums,0,size-1);


    }
};